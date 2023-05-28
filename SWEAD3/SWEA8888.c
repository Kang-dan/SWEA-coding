//답은 맞는데, 시간초과로 통과 못함.
#include <stdio.h>
int main(void){
    int Tc, N, T, P, i, j, k;
    scanf("%d", &Tc);
    for(i=1; i<=Tc; i++){
        scanf("%d %d %d", &N, &T, &P); //N명, T개 문제, P참가자 번호
        int num[N+1][T+1];
        for(j=1; j<=N; j++){
            for(k=1; k<=T; k++)
                scanf(" %d", &num[j][k]);
        }

        //각 문제 점수 매기기
        int t[2001] = {0}; //문제점수
        int count;
        for(j=1; j<=T; j++){
            for(k=1; k<=N; k++){
                if(num[k][j]==0) t[j]++;
            }
        }

        //참가자 각 점수 매기기
        int n[2001] = {0}; //참가자 점수
        int n_count[2001] = {0}; //참자가가 푼 문제수
        for(j=1; j<=N; j++){
            for(k=1; k<=T; k++){
                if(num[j][k]==1){
                    n_count[j]++; //문제수
                    n[j] += t[k]; //점수
                }
            }
        }

        //등수 매기기
        int result[2001] = {0};
        int c=0;
        for(j=1; j<=N; j++){
            for(k=1; k<=N; k++){
                if(n[j] < n[k]) result[j]++;
                else if(n[j]==n[k] && n_count[j]<n_count[k]) result[j]++;
                else if(n[j]==n[k] && n_count[j]==n_count[k] && j>k) result[j]++;
            }
            if(j==P){
                printf("#%d %d %d\n", i, n[j], result[j]+1);
                break;
            }
        }

    }
    return 0;
}