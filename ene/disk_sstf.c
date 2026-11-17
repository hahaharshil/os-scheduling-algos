#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 8;
    int r[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int used[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    int total = 0;
    int cur = head;

    printf("%d", cur);
    for(int c = 0; c < n; c++){

        int k = -1;
        for(int i = 0; i < n; i++){
            if(used[i] == 0){
                if(k == -1 || abs(r[i] - cur) < abs(r[k] - cur)){
                    k = i;
                }
            }
        }

        total = total + abs(r[k] - cur);
        cur = r[k];
        used[k] = 1;
        printf(" -> %d", cur);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}
