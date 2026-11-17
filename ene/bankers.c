#include <stdio.h>

int main(){
    int n = 4;
    int alloc[4] = {2, 3, 2, 1};
    int max[4]   = {7, 5, 4, 3};
    int avail = 2;

    int need[4];
    int done[4] = {0, 0, 0, 0};
    int seq[4];
    int count = 0;

    for(int i = 0; i < n; i++){
        need[i] = max[i] - alloc[i];
    }

    for(int pass = 0; pass < n; pass++){
        for(int i = 0; i < n; i++){
            if(done[i] == 0 && need[i] <= avail){
                avail = avail + alloc[i];
                done[i] = 1;
                seq[count] = i;
                count++;
            }
        }
    }

    if(count < n){
        printf("UNSAFE\n");
    }
    else{
        printf("SAFE: ");
        for(int i = 0; i < n; i++){
            printf("P%d ", seq[i]);
        }
        printf("\n");
    }
    return 0;
}
