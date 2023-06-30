/* 5688. 세제곱근을 찾아라
양의 정수 N에 대해 N = X3가 되는 양의 정수X 를 구하여라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1≤N≤1018) 이 주어진다.

[출력]
각 테스트 케이스마다 첫 번째 줄에는‘#T’(T는 테스트케이스 번호를 의미하며 1부터 시작한다.)를 출력하고, N = X3가 되는 양의 정수 X를 출력한다.
만약 이런 X가 존재하지 않으면 -1을 출력한다.
*/

#include <stdio.h>
int main(){
    int T, i;
    long long N, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%lld", &N);
        for(j=1; j<=N; j++){
            if(N==j*j*j){
                printf("#%d %lld\n", i, j);
                break;
            }
            else if(N<j*j*j){
                printf("#%d -1\n", i);
                break;
            }
        }
    }
    return 0;
}