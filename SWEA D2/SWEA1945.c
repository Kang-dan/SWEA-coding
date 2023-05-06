//1945.간단한 소인수분해
/*
숫자 N은 아래와 같다.
N=2a x 3b x 5c x 7d x 11e

N이 주어질 때 a, b, c, d, e 를 출력하라.

[제약 사항]
N은 2 이상 10,000,000 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N 이 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include <stdio.h>
int main() {
    int T, N, i;
    int a,b,c,d,e;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        a=0; b=0; c=0; d=0; e=0;
        scanf("%d", &N);
        while(N>1){
            if(N%2==0) {
                a++; N/=2;
            }
            if(N%3==0){
                b++; N/=3;
            }
            if(N%5==0){
                c++; N/=5;
            }
            if(N%7==0){
                d++; N/=7;
            }
            if(N%11==0){
                e++; N/=11;
            }
        }
        printf("#%d %d %d %d %d %d\n",i, a,b,c,d,e);
    }
    return 0;
}

//TSJ님 코드
/*
#include <stdio.h>
 
int main()
{
    int T, t;
 
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        int n;
        int _2 = 0, _3 = 0, _5 = 0, _7 = 0, _11 = 0;
        scanf("%d", &n);
 
        while (n % 2 == 0 && n > 0)
        {
            _2++;
            n /= 2;
        }
        while (n % 3 == 0 && n > 0)
        {
            _3++;
            n /= 3;
        }
        while (n % 5 == 0 && n > 0)
        {
            _5++;
            n /= 5;
        }
        while (n % 7 == 0 && n > 0)
        {
            _7++;
            n /= 7;
        }
        while (n % 11 == 0 && n > 0)
        {
            _11++;
            n /= 11;
        }
 
        printf("#%d %d %d %d %d %d\n", t, _2, _3, _5, _7, _11);
    }
 
    return 0;
}
*/