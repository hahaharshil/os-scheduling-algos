#include <stdio.h>
#include <stdbool.h>

#define MAX_PROC 5

typedef struct{
    int id;
    int bt;

    int wt;
    int tat;
    int at;
    bool used;
    int p;
}process;


process list[MAX_PROC];


void ps_preemptive(process plist[]){
    int rem[MAX_PROC], t = 0, done = 0, total = 0;

    for(int i = 0; i < MAX_PROC; i++){
        rem[i] = plist[i].bt;
        if(plist[i].used) total++;
    }

    while(done < total){
        int pick = -1;

        for(int i = 0; i < MAX_PROC; i++){
            if(!plist[i].used || rem[i] == 0 || plist[i].at > t) continue;

            if(pick == -1 || plist[i].p < plist[pick].p ||
              (plist[i].p == plist[pick].p && plist[i].at < plist[pick].at)) pick = i;
        }

        if(pick == -1){ t++; continue; }

        rem[pick]--;
        t++;

        if(rem[pick] == 0){
            plist[pick].tat = t - plist[pick].at;
            plist[pick].wt = plist[pick].tat - plist[pick].bt;
            done++;
        }
    }
}

bool add_process(int id, int bt, int p){
    if(id < 0 || id >= MAX_PROC) return false;
    if(list[id].used) return false;
    if(bt <= 0) return false;
    list[id] = (process){ .id = id, .bt = bt, .p = p, .used = true, .at = 0};
    return true;
}



float avg_wt(process plist[], int n){

    int total_wt = 0;

    for(int i = 0; i < MAX_PROC; i++){
        if(plist[i].used){
            total_wt += plist[i].wt;
        }else
            continue;
    }

    return (float)total_wt/(float)n;

}



float avg_tat(process plist[], int n){

    int total_tat = 0;

    for(int i = 0; i < MAX_PROC; i++){
        if(plist[i].used){
            total_tat += plist[i].tat;
        }else
            continue;
    }

    return (float)total_tat/(float)n;

}

int main(void){
    int n; scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int id, bt, p;

        scanf("%d %d %d", &id, &bt, &p);

        add_process(id, bt, p);
    }


    ps_preemptive(list);


    printf("IT \t BT \t WT \t TAT \n");

    for(int i = 0; i < MAX_PROC; i++){
        printf("%d \t %d \t %d \t %d\n", list[i].id, list[i].bt, list[i].wt, list[i].tat);
    }

    printf("Avg waiting time:  %f \n", avg_wt(list, n));
    printf("Avg Turn around time:  %f", avg_tat(list, n));

    return 0;

}
