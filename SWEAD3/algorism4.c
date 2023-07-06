/*1959.두 개의 숫자열
N 개의 숫자로 구성된 숫자열 Ai (i=1~N) 와 M 개의 숫자로 구성된 숫자열 Bj (j=1~M) 가 있다.
아래는 N =3 인 Ai 와 M = 5 인 Bj 의 예이다.

Ai 나 Bj 를 자유롭게 움직여서 숫자들이 서로 마주보는 위치를 변경할 수 있다.
단, 더 긴 쪽의 양끝을 벗어나서는 안 된다.
서로 마주보는 숫자들을 곱한 뒤 모두 더할 때 최댓값을 구하라.
위 예제의 정답은 아래와 같이 30 이 된다.
 
[제약 사항]
N 과 M은 3 이상 20 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,
두 번째 줄에는 Ai,
세 번째 줄에는 Bj 가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/ 

#include <stdio.h>
int main(){
    int T, N, M, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N, &M);
        int num1[N], num2[M];
        for(j=0; j<N; j++){
            scanf("%d", &num1[j]);
        }
        for(j=0; j<M; j++){
            scanf("%d", &num2[j]);
        }

        int sum = 0, max=-9999, b;
        if(N>=M){
            b = 0;
            for(j=0; j<=N-M; j++){
                sum = 0;
                for(int a=0; a<M; a++){
                    sum += num1[b+a]*num2[a];
                }
                b++;
                if(max < sum) max = sum;
            }
            printf("#%d %d\n", i, max);
        }
        else if(N<=M){
            b = 0;
            for(j=0; j<=M-N; j++){
                sum = 0;
                for(int a=0; a<N; a++){
                    sum += num2[b+a]*num1[a];
                }
                b++;
                if(max < sum) max = sum;
            }
            printf("#%d %d\n", i, max);
        }
    }
    return 0;
}