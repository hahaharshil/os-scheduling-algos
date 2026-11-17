#include <stdio.h>

int main(){
    int n = 10;
    int r[10] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int f[3] = {-1, -1, -1};
    int pf = 0;

    for(int i = 0; i < n; i++){

        int k = -1;
        for(int j = 0; j < 3; j++){
            if(f[j] == r[i]){
                k = j;
            }
        }

        if(k == -1){
            int far = -1;
            for(int j = 0; j < 3; j++){
                int next = i + 1;
                while(next < n && r[next] != f[j]){
                    next++;
                }
                if(f[j] == -1){
                    next = n + 1;
                }
                if(next > far){
                    far = next;
                    k = j;
                }
            }

            f[k] = r[i];
            pf++;
        }
    }

    printf("Page faults = %d\n", pf);
    return 0;
}
