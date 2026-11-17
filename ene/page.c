#include <stdio.h>


int main(int argc, char *argv[]){

    int n, F, r[10], f[3] = {-1, -1, -1}, pf = 0, t[10];
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &r[i]);

    for(int i = 0; i < n; i++){
        int k = -1;
        for(int j = 0; j < 3; j++)if(f[j] == r[i]) k = j; 
        if(k == -1){
            for(int j = 0; j < 3; j++) if(t[j] < t[k]) k = j;
            f[k] = r[i];
            pf++;
        }
            t[k] = i; 
    }
    printf("%d \n", pf);
}
