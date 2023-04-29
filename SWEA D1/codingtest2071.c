/*
SWEA 2071. 평균값 구하기
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
10개의 수를 입력 받아, 평균값을 출력하는 프로그램을 작성하라.
(소수점 첫째 자리에서 반올림한 정수를 출력한다.)

[제약 사항]
각 수는 0 이상 10000 이하의 정수이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/
#include <stdio.h>
#include <math.h>

int main() {
    int T, num, sum, avg, i, j;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        sum = 0;
        for(j=0; j<10; j++){
            scanf("%d", &num);
            sum = sum + num;
        }
        avg = round((double)sum / 10);
        printf("#%d %d\n", i, avg);
    }
    return 0;
}







// #include <stdio.h>
// #include <math.h> //핵심!!

// int main() {
//     int i, j, t, a, sum, avg;

//     scanf("%d", &t);

//     for(i=1; i<=t; i++){
//         sum = 0;
//        // avg = 0; 이건 안써도 됨
//         for(j=0; j<10; j++){
//             scanf("%d", &a);
//             sum = sum + a;
//         }
//         avg = round((double)sum / 10); //소수점 첫째 자리에서 반올림 핵심!!!

//         printf("#%d %d\n", i, avg);
//     }

//     return 0;
// }

//mm 님이 푼 답
// #include <stdio.h>
 
// int num[10];
// double sum;
// double avg;
// int result;
 
// void average()
// {
//     sum = 0.0;
 
//     for (int i = 0; i < 10; i++)
//     {
//         sum += (double)num[i];
//     }
 
//     avg = (sum / 10.0);
//     result = (int)(avg + 0.5);
 
// }
 
// int main()
// {
//     int t;
//     scanf("%d", &t);
 
//     for (int tc = 1; tc <= t; tc++)
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             scanf("%d", &num[i]);
//         }
//         average();
 
//         printf("#%d %d\n", tc, result);
//     }
 
//     return 0;
// }