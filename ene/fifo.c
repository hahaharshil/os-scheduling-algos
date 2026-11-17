#include <stdio.h>

int main(){
    int r[10] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int f[3] = {-1, -1, -1};
    int t[3] = {-1, -1, -1};
    int pf = 0;

    for(int i = 0; i < 10; i++){

        int k = -1;
        for(int j = 0; j < 3; j++){
            if(f[j] == r[i]){
                k = j;
            }
        }

        if(k == -1){
            k = 0;
            for(int j = 1; j < 3; j++){
                if(t[j] < t[k]){
                    k = j;
                }
            }

            f[k] = r[i];
            pf++;
            t[k] = i;
        }
    }

    printf("Page faults = %d\n", pf);
    return 0;
}
