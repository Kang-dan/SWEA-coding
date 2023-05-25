//8821. 적고 지우기
/*
진수는 어린 동욱이에게 숫자 공부를 시키고 있다.
진수는 숫자를 여러 번 말한다.
그러면 동욱이는 진수가 부르는 숫자를 공책에 적거나 지운다.
숫자를 적을 때는 공책에 그 숫자가 적혀 있지 않을 때이고,
숫자를 지울 때는 공책에 그 숫자가 적혀 있을 때이다.
처음 공책에는 어떤 숫자도 적혀 있지 않다고 할 때,
마지막에 공책에 적힌 숫자의 개수를 구하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 ‘0’에서 ‘9’사이의 숫자로 이루어진
길이 1이상 104이하의 문자열이 주어진다.
문자열은 진수가 말하는 숫자를 순서대로 나타낸다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
각 테스트 케이스 마다 마지막에 공책에 적힌 숫자의 개수를 출력한다.
*/

//내 코드 (이건 통과안됨. 왜???!)
#include <stdio.h>
#include <string.h>

int main(void){
    int T, i, j, k;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        char record[10000];
        scanf("%s", &record);
        int count[10] = {0};
        for(j=0 ; j<strlen(record); j++){
            count[record[j]-'0']++;
        }
        int sum = 0;
        for(j=0; j<=9; j++){
            sum += count[j]%2;
        }      
        printf("#%d %d\n", i, sum);
    }
    return 0;
}


//예언가님 코드
/*
#include <stdio.h>
 
int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 1; i <=t; i++) {
        printf("#%d ", i);
        int n;
        int sum = 0;
        int temp = 0;
        int max = 0;
        char arr[10000];
        int brr[10] = { 0 };
        scanf("%s", &arr);
        for (int j = 0; j < strlen(arr); j++) {
            brr[arr[j]-'0']++;
        }
        for (int j = 0; j < 10; j++) {
            if (brr[j] % 2 == 1) {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
}
*/