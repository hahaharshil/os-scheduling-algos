#include <stdio.h>
#include <stdbool.h>


#define Q 2
#define M 5


typedef struct{
    int id;
    int bt;

    int wt;
    int tat;
    int at;
    int ct;
    int r_bt;
}process;

process list[M];


bool add_process(int id, int bt, int at){
   list[id] = (process){ .id = id, .bt = bt, .at = at, .r_bt = bt}; 
    return 1;
}


void rr(int n){
    int head = 0, tail = 0, next = 0, t = 0, done = 0;
    int queue[100];

    while(n > done){
        while(n > next && list[next].at <= t) queue[tail++] = next++;
        if(head == tail) { t = list[next].at; continue; }

        int i = queue[head++];
        int s = list[i].r_bt < Q ? list[i].r_bt : Q;

        t +=  s;
        list[i].r_bt -= s;

        while(n > next && list[next].at <= t) queue[tail++] = next++;

        if(list[i].r_bt > 0){
            queue[tail++] = i;
        }else{
            list[i].ct = t;
            list[i].tat = list[i].ct- list[i].at;
            list[i].wt = list[i].tat - list[i].bt;
            done++;
        }
    }
}


int main(void){
    printf("Enter the number of process: \n");
    int n;
    if(scanf("%d", &n) != 1) return 1;

    for(int i = 0; i < n; i++){
        int id, bt, at;
        

        if(scanf("%d %d %d", &id, &bt, &at) != 3) return 1;

        add_process(id, bt, at);
    }


    rr(n);

    printf("id \t bt \t wt \t tat \n"); 

    for(int i = 0; i < n; i++){
        process p = list[i];
        printf("%d \t %d \t %d \t %d \n", p.id, p.bt, p.wt, p.tat);
    }
}
