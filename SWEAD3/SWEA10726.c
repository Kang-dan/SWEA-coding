//10726.이진수 표현
/*
정수 N, M 이 주어질 때, M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지 아닌지를 판별하여 출력하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되었다.
첫 번째 줄에 정수 N, M이 주어진다. (1 ≤ N ≤ 30 , 0 ≤ M ≤ 108)

[출력]
각 테스트 케이스마다 한 줄씩
마지막 N개의 비트가 모두 켜져 있다면 ON
아니면 OFF 를 출력하라.
*/

#include <stdio.h>
int main(){
    int T, N,M,i,j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N,&M);
        int a[100000];
        j=0;
        int k = N;
        while(k--){
            a[j] = M%2;
            M/=2;
            j++;
        }
        for(j=0; j<N; j++){
            if(a[j]==0){
                printf("#%d OFF\n",i);
                break;
            }
        }
        if(j==N) printf("#%d ON\n", i);
    }
    return 0;
}

//Chat-GPT3.5
/*
#include <stdio.h>

// 이진수의 마지막 N 비트가 모두 1로 켜져 있는지 판별하는 함수
int checkBits(int n, int m) {
    int mask = (1 << n) - 1; // 마지막 N 비트에 해당하는 비트 마스크 생성
    return (m & mask) == mask; // 비트 마스크와 M을 AND 연산하여 결과 판별
}

int main() {
    int TC, i;
    scanf("%d", &TC); // 테스트 케이스 수 입력

    for(i=1; i<=TC; i++) {
        int N, M;
        scanf("%d %d", &N, &M); // N과 M 입력

        if (checkBits(N, M))
            printf("#%d ON\n", i);
        else
            printf("#%d OFF\n", i);
    }

    return 0;
}
*/