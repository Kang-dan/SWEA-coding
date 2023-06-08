/* 7728. 다양성 측정
숫자는 다양성을 가지고 있다. 다양성이란, 숫자를 구성하는 수의 종류를 의미한다.
예를 들어서 1512 라는 숫자는 ‘1’, ‘5’, ‘2’로 구성되어 있기 때문에 다양성이 3이다.
숫자가 주어졌을 때 그 숫자의 다양성을 구하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 100)가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 다양성을 체크하고 싶은 숫자 X(1 ≤ X ≤ 109) 가 주어진다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
주어진 숫자의 다양성을 출력하라.
*/

//내코드. 문자배열로 구현.
#include <stdio.h>
#include <string.h>

int main(){
    int T, i, j;
    char X[11];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s", &X[0]);
        int flag[10] = {0}; //0~9까지

        for(j=0; j<strlen(X); j++){
            flag[X[j]-48] = 1;
        }

        int result = 0;
        for(j=0; j<10; j++){
            if(flag[j]==1) result++;
        }
        printf("#%d %d\n", i, result);
    }
    return 0;
}

//다른코드. 숫자나누기로 구현.
#include<stdio.h>
 
int main()
{
    int t, a;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int brr[10]={0,};
        printf("#%d ", tc);
        scanf("%d", &a);
        int k = 0;
        while (1) {
            if (a < 10) {
                brr[a] = 1;
                break;
            }
            brr[a%10] = 1;
            a /= 10;
        }
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (brr[j] == 1) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}