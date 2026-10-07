#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

static int byp(const void *a, const void *b){
    const process *pa = a;
    const process *pb = b;

    if(pa->p != pb->p) return (pa->p > pb->p) - (pa->p < pb->p);
    
    return (pa-> id > pb->id) - (pa->id < pb->id);

}


void psort(process plist[]){
    qsort(plist, (size_t)MAX_PROC, sizeof list[0], byp);
}

bool add_process(int id, int bt, int p){
    if(id < 0 || id >= MAX_PROC) return false;
    if(list[id].used) return false;
    if(bt <= 0) return false;
    list[id] = (process){ .id = id, .bt = bt, .p = p, .used = true, .at = 0};
    return true;
}



bool wait_time(process plist[]){
    int wt = 0;

    for(int i = 0; i < MAX_PROC; i++){
            
        if(plist[i].used){
            plist[i].wt = wt; 
            wt += plist[i].bt;
        }else
            continue;
    }
    return 1;
}


bool turn_around_time(process plist[]){
    
    for(int i = 0; i < MAX_PROC; i++){ 
        if(plist[i].used){
            plist[i].tat = plist[i].wt + plist[i].bt; 
        }else
            continue;
    }
    return 1;
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


    psort(list);


    wait_time(list);
    turn_around_time(list);


    printf("IT \t BT \t WT \t TAT \n");
    
    for(int i = 0; i < MAX_PROC; i++){
        printf("%d \t %d \t %d \t %d\n", list[i].id, list[i].bt, list[i].wt, list[i].tat);
    }

    printf("Avg waiting time:  %f \n", avg_wt(list, n));
    printf("Avg Turn around time:  %f", avg_tat(list, n));
    
    return 0;

}

