#include <stdio.h>

int main(){
    int b[5] = {100, 500, 200, 300, 600};
    int p[4] = {212, 417, 112, 426};

    for(int i = 0; i < 4; i++){

        int k = -1;
        for(int j = 0; j < 5; j++){
            if(b[j] >= p[i]){
                if(k == -1 || b[j] < b[k]){
                    k = j;
                }
            }
        }

        if(k == -1){
            printf("P%d (%d) -> not allocated\n", i, p[i]);
        }
        else{
            printf("P%d (%d) -> block %d\n", i, p[i], k);
            b[k] = b[k] - p[i];
        }
    }
    return 0;
}
