#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 8;
    int r[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;

    int total = 0;
    int cur = head;

    printf("%d", cur);
    for(int i = 0; i < n; i++){
        total = total + abs(r[i] - cur);
        cur = r[i];
        printf(" -> %d", cur);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}
