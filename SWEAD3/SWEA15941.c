//15941.평행사변형
/*
정수 N이 주어질 때, 모든 변의 길이가 N인 가장 넓은 평행사변형의 넓이를 출력하라. 이 넓이는 정수임이 보장된다.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.
첫 번째 줄에 정수 N이 주어진다. (1<=N<=100)

[출력]
각 테스트 케이스 마다 한 줄씩 문제의 정답을 출력하라.
*/

#include <stdio.h>
int main(){
    int TC, N, i;

    scanf("%d", &TC);
    for(i=1; i<=TC; i++){
        scanf("%d", &N);
        int a = N*N;
        printf("#%d %d\n", i, a);
    }
    return 0;
}