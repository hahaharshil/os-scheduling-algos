#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 8;
    int r[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int end = 199;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(r[j] > r[j + 1]){
                int tmp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tmp;
            }
        }
    }

    int s = 0;
    while(s < n && r[s] < head){
        s++;
    }

    int total = 0;
    int cur = head;
    printf("%d", cur);

    for(int i = s; i < n; i++){
        total = total + abs(r[i] - cur);
        cur = r[i];
        printf(" -> %d", cur);
    }

    total = total + (end - cur);
    cur = end;
    printf(" -> %d", cur);

    for(int i = s - 1; i >= 0; i--){
        total = total + abs(r[i] - cur);
        cur = r[i];
        printf(" -> %d", cur);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}
