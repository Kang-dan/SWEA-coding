//11736.평범한 숫자
/*
1 이상 N 이하의 정수가 적혀 있는 길이 N의 순열 p1, p2, …, pN이 있다. 수열에 있는 모든 숫자는 서로 다르다. 2 ≤ i ≤ N-1이며, pi-1, pi, pi+1 중 pi가 최솟값도, 최댓값도 아니라면 pi를 평범한 숫자라고 정의한다. 주어진 순열에서 평범한 숫자의 개수는 몇 개인가?

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.
∙ 첫 번째 줄에 정수 N 이 주어진다. (3 ≤ N ≤ 20)
∙ 이후 N개의 정수 pi가 주어진다. (3 ≤ pi ≤ N) 모든 pi는 서로 다르다.

[출력]
각 테스트 케이스마다 정답을 출력하라.
*/

#include <stdio.h>
int main(void){
    int T, N, i, j, k;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        int p[N];
        for(j=0; j<N; j++){
            scanf("%d", &p[j]);
        }

        int result = 0;
        k=0;
        while(k < N-3+1){
            if((p[k] < p[k+1]) && p[k+1] < p[k+2]){
                result++;
            }
             if(p[k] > p[k+1] && p[k+1] > p[k+2]){
                result++;
            }
            k++;
        }
        printf("#%d %d\n", i, result);
    }
    return 0;
}