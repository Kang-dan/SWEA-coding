/* 7532. 세영이의 SEM력 연도
세영이는 태양(S)과 지구(E)와 달(M)을 이용하여 연도를 기억한다.
이를 이용한 방법을 SEM력이라고 부르며, SEM력은 자연수 3개, S, E, M으로 이루어져있다.
첫 번째 수는 태양, 두 번째는 지구, 세 번째는 달과 관련 있다.

AD 1년에 SEM력을 1 1 1로 정의했다.
1년이 지날 때마다 각 수를 1씩 증가시키는데,
S는 365보다 커지면 1로, E는 24보다 커지면 1로, M은 29보다 커지면 1로 돌아온다.
예를 들어서 AD 24년은 24 24 24이고 AD 25년은 25 1 25이다.
SEM력으로 이루어진 연도가 주어졌을 때, 이를 만족하는 실제 연도 중 가능한 가장 빠른 연도를 구하여라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 2000)가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 SEM력으로 이루어진 연도를 의미하는 자연수 3개,
S, E, M(1 ≤ S ≤ 365, 1 ≤ E ≤ 24, 1 ≤ M ≤ 29)가 공백으로 구분되어 주어진다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
주어진 SEM력 연도를 만족하는 실제 연도 중, 가능한 가장 빠른 연도를 출력하라.
*/

//Chat-GPT3.5 협업
#include <stdio.h>
int main(){
    int T, S, E, M, i;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d", &S, &E, &M);

        int year = 1;
        while(1){
             if ((year - S) % 365 == 0 && (year - E) % 24 == 0 && (year - M) % 29 == 0) {
                printf("#%d %d\n", i, year);
                break;
            }
            year++;
        }
    }
    return 0;
}

//다른방법
#include<stdio.h>
#include<string.h>
 
int main()
{
    int n, t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int s, e, m;
        int s1 = 0;
        int e1 = 0;
        int m1 = 0;
        printf("#%d ", tc);
        scanf("%d %d %d", &s,&e,&m);
        int cnt = 0;
        while (1) {
            if ((s1 == s && e1 == e) && (m1 == m)) {
                printf("%d\n", cnt);
                break;
            }
            else {
                s1++; e1++; m1++;
                if (s1 == 366) {
                    s1 = 1;
                }
                if (e1 == 25) {
                    e1 = 1;
                }
                if (m1 == 30) {
                    m1 = 1;
                }
            }
            cnt++;
        }
    }
    return 0;
}