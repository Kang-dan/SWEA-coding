//1954.달팽이 숫자
/*
달팽이는 1부터 N*N까지의 숫자가 시계방향으로 이루어져 있다.
다음과 같이 정수 N을 입력 받아 N크기의 달팽이를 출력하시오.

[예제]
N이 3일 경우,

N이 4일 경우,

[제약사항]
달팽이의 크기 N은 1 이상 10 이하의 정수이다. (1 ≤ N ≤ 10)

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스에는 N이 주어진다.

[출력]
각 줄은 '#t'로 시작하고, 다음 줄부터 빈칸을 사이에 두고 달팽이 숫자를 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
입력예시)
2    
3   
4   
출력예시)
#1
1 2 3
8 9 4
7 6 5
#2
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7 */

#include <stdio.h>
int main(){
    int T, N, i, j, k;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        int num[N][N];
        int flag[N][N];
        //숫자쓰면 1로 바꿔주기
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                flag[j][k] = 0;
            }
        }
        int a = 0; // N*N값이 되면 멈추게하기
        for(j=0; j<N; j++){
            if(a==N*N){
                break;
            }
            else {
            //동쪽
            for(k=0; k<N; k++){
                if(a == N*N) break;
                else if (flag[j][k]==0){
                    a++;
                    num[j][k] = a;
                    flag[j][k] = 1;
                }
            }
            //남쪽
            for(k=0; k<N; k++){
                if(a == N*N) break;
                else if(flag[k][N-1-j]==0){
                    a++;
                    num[k][N-1-j] = a;
                    flag[k][N-1-j] = 1;
                }
            }
            //서쪽
            for(k=N-1; k>=0; k--){
                if(a == N*N) break;
                else if(flag[N-1-j][k]==0){
                    a++;
                    num[N-1-j][k] = a;
                    flag[N-1-j][k] = 1;
                }
            }
            //북쪽
            for(k=N-1; k>=0; k--){
                if(a == N*N) break;
                else if(flag[k][j]==0){
                    a++;
                    num[k][j] = a;
                    flag[k][j] = 1;
                }
            }
            }
        }
        printf("#%d\n",i);
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                printf("%d ", num[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}
