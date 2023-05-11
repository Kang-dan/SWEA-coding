//16800.구구단 걷기 (시간걸림)
/*
당신은 무한히 많은 행과 열이 있는 곱셈표 위에 서 있다. (i, j)셀에는 정수 ixj 가 적혀 있다. (만약 행과 열이 9개라면 이는 구구단 표와 동일하다.) 현재 당신의 위치는 셀 (1, 1) 이다.
당신은 곱셈표의 오른쪽이나 아래쪽 방향으로 이동할 수 있다. 즉, 당신이 (i, j)에 서 있다면, (i+1, j)나 (i, j+1)로 이동할 수 있다.
정수 N이 주어질 때, N이 적혀 있는 어떤 셀에 도착하기 위해서 최소 몇 번 움직여야 하는가?

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.
 l 첫 번째 줄에 정수 N이 주어진다. (2 <= N <= 10^12)

[출력]
각 테스트 케이스 마다 한 줄씩 문제의 정답을 출력하라.
*/

#include <stdio.h>
int main(){
    int T, i,j;
    long long N;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%lld", &N);
        long long a=1, b, c;
        while(a*a<=N){ //a*a하는 이유는 N의 약수는 N의 제곱근을 기준으로 대칭적으로 존재하기 때문. 안그럼 시간초과됨.
            if(N%a == 0){
                b = N/a;
                c = (a-1)+(b-1);
            }
            a++;
        }
        printf("#%d %lld\n", i, c);
    }
    return 0;
}


//다빈치코드님 코드
// #include<stdio.h>
 
// int main() {
 
//     int t;
//     long long n;
//     long long arr[100000];
//     scanf("%d", &t);
//     for (int i = 0; i < t; i++) {
//         scanf("%lld", &n);
 
//         long long j;
//         long long count = 0;
//         //long long x_min;
//         //long long y_min;
//         long long sum_min= 9223372036854775807;
//         long long x[10000], y[10000];
 
//         for (j = 1; j <= n/j; j++) {
//             if (n % j == 0) {
//                 x[count] = j;
//                 y[count] = n / j;
//                 count++;
//             }
//         }
//         count--;
//         for (j = 0; j <= count; j++) {
//             long long sum = x[count] - 1 + y[count] - 1;
//             if (sum < sum_min) {
//                 sum_min = sum;
//             }
//         }
//         arr[i] = sum_min;
//     }
     
//     for (int i = 0; i < t; i++) {
//         printf("#%d %lld\n", i + 1, arr[i]);
//     }
//     return 0;
// }