//1961.숫자 배열 회전
/*
N x N 행렬이 주어질 때,
시계 방향으로 90도, 180도, 270도 회전한 모양을 출력하라.

[제약 사항]
N은 3 이상 7 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N이 주어지고,
다음 N 줄에는 N x N 행렬이 주어진다.

[출력]
출력의 첫 줄은 '#t'로 시작하고,
다음 N줄에 걸쳐서 90도, 180도, 270도 회전한 모양을 출력한다.
입력과는 달리 출력에서는 회전한 모양 사이에만 공백이 존재함에 유의하라.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력 예시)
1
3
1 2 3
4 5 6
7 8 9

출력)
#1
741 987 369
852 654 258
963 321 147
*/

#include <stdio.h>
int main() {
    int T, N, i, j, k;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d",&N);
        int num[N][N];
        //행렬 입력
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                scanf("%d", &num[j][k]);
            }
        }
        int a=0;
        int b=N-1;
        int c=N-1;
        printf("#%d\n", i);
        while(a<N && b>=0 && c>=0){
            //90도
            for(k=N-1; k>=0; k--){
                printf("%d", num[k][a]);
            }
            a++;
            printf(" ");
            //180도
            for(k=N-1; k>=0; k--){
                printf("%d", num[b][k]);
            }
            b--;
            printf(" ");
            //270도
            for(k=0; k<N; k++){
                printf("%d", num[k][c]);
            }
            c--;
            printf(" ");
            printf("\n");
        }
    }
    return 0;
}

//Chat-GPT3.5
/*
#include <stdio.h>

int main() {
    int T, N, i, j, k;

    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        scanf("%d", &N);
        int num[N][N];

        // 행렬 입력
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                scanf("%d", &num[j][k]);
            }
        }

        printf("#%d\n", i);
        for (j = 0; j < N; j++) {
            // 90도 회전
            for (k = N - 1; k >= 0; k--) {
                printf("%d", num[k][j]);
            }
            printf(" ");

            // 180도 회전
            for (k = N - 1; k >= 0; k--) {
                printf("%d", num[N - 1 - j][k]);
            }
            printf(" ");

            // 270도 회전
            for (k = 0; k < N; k++) {
                printf("%d", num[k][N - 1 - j]);
            }
            printf("\n");
        }
    }
    return 0;
}
*/