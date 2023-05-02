//1976.시각 덧셈
/*
시 분으로 이루어진 시각을 2개 입력 받아, 더한 값을 시 분으로 출력하는 프로그램을 작성하라.
(시각은 12시간제로 표시한다. 즉, 시가 가질 수 있는 값은 1시부터 12시이다.)

[제약 사항]
시는 1 이상 12 이하의 정수이다. 분은 0 이상 59 이하의 정수이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 4개의 수가 주어진다.
첫 번째 수가 시를 나타내고 두 번째 수가 분을 나타낸다. 그 다음 같은 형식으로 두 번째 시각이 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고 공백을 한 칸 둔 다음, 시를 출력하고 공백을 한 칸 둔 다음 분을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

예시 입력)
3 
3 17 1 39
8 22 5 10
6 53 2 12 
출력)
#1 4 56
#2 1 32
#3 9 5
*/

#include <stdio.h>
int main() {
    int T, h1, m1, h2, m2;
    int H, M; //시간은 1~12까지, 분은 0~59까지
    int i;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        H=0; M=0;
        scanf("%d %d %d %d", &h1,&m1,&h2,&m2);
        H = h1 + h2;
        M = m1 + m2;
        if(M > 59){
            M = M%60;
            H++;
        }
        if (H==24){
            H = 12;
        }
        if(H>12 && H<24){
            H = H%12;
        }
        printf("#%d %d %d\n", i, H, M);
    }
    return 0;
}

/* 피나는거시름님 코드
#include <stdio.h>
 
int main() {
    int T;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++) {
        int arr[4];
        for (int i = 0; i < 4; i++)
            scanf("%d", &arr[i]);
 
        int hour = 0, minute = 0;
         
        minute = arr[1] + arr[3];
        hour = minute / 60;
        minute %= 60;
         
        hour += (arr[0] + arr[2]) % 12;
 
        printf("#%d %d %d\n", testCase, hour, minute);
    }
}
*/