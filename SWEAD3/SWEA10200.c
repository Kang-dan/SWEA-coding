//10200.구독자 전쟁
/*
최근 어떤 동영상 플랫폼에서 P채널과 T채널이 구독자 수 1위를 놓고 치열한 경쟁을 벌이고 있다.
영은이는 자신의 주위 사람들은 어떤 채널을 구독하고 있을지 궁금해하여, N명의 사람들에게 아래 두 질문을 하였다.
-  P채널을 구독하고 있나요?
-  T채널을 구독하고 있나요?
그 결과, A명이 1번 질문에 ‘네’라고 답했고, B명이 2번 질문에 ‘네’라고 답했다.
이때, P채널과 T채널 모두 구독하고 있는 사람들이 최소 몇 명, 최대 몇 명인지 구하는 프로그램을 작성하라. 

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 세 개의 정수 N (1 ≤ N ≤ 100), A, B (0 ≤ A, B ≤ N)이 공백 하나를 사이로 두고 순서대로 주어진다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
P채널과 T채널 모두 구독하고 있는 사람의 수의 최댓값과 최솟값을 공백 하나를 사이로 두고 차례대로 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
    int T, N, A, B, i;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d", &N, &A, &B);
        if(N==A && N==B) {
            printf("#%d %d %d\n", i, A, A);
        }
        else if(A+B<=N){
            if(A>B) printf("#%d %d 0\n",i, B);
            else printf("#%d %d 0\n", i, A);
        }
        else if(A+B>N){
            if(A>B) printf("#%d %d %d\n", i, B, (A+B)-N);
            else printf("#%d %d %d\n", i, A, (A+B)-N);
        }
    }
    return 0;
}

//코딩의 신님 코드
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N, A, B, Maxterm, Minterm = 0;
        scanf("%d %d %d", &N, &A, &B);
        if (A >= B) Maxterm = B;
        else if (A < B) Maxterm = A;
        if (A + B > N) Minterm = A + B - N;
        printf("#%d %d %d\n", i, Maxterm, Minterm);
    }
    return 0;
}
*/
