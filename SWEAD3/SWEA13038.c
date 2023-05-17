//13038.
#include <stdio.h>
int main(void){
    int T, N, i, j, k, day, tmp, b;
    int a[8];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        for(j=0; j<7; j++){
            scanf("%d", &a[j]);
        }
        day = 0;
        k=0; tmp = 0;
        while(1){
            b = 0;
            int c = 0;
            for(j=0; j<7; j++){
                if(a[j] == 1) {
                    c++;
                    if(c == 1) b = j;
                    day++;
                }
                if(day == N) {
                    b = j-b+1;
                    break;
                }
            }
            if(day == N) break;
            else if(day != N){
            day = 0;
            b = 0;
            for(j=0; j<7; j++){
                if(a[j] == 1){
                    b = 7-j;
                    break;
                }
            }
            if(day == N) break;
            if(k==7) {
                k=0; //순환
                tmp++;
            }
            if(a[k] == 1) day++;
            k++;
            }
        }
        printf("#%d %d\n", i, tmp*7+k+b);
    }
    return 0;
}