/* 7272. 안경이 없어!
어느 날 경근이는 알파벳 대문자로 이루어진 두 문자열을 비교해야 했는데, 이 날은 공교롭게도 안경이 없었다.
경근이는 매우 눈이 나빠서 안경을 벗으면 문자열을 문자 단위로 구별할 수는 있지만, 두 문자가 정확히 같은 지는 알지 못한다.
특히 알파벳 대문자 같은 경우 문자에 나 있는 구멍의 개수가 같으면 같은 문자이고, 다르면 다른 문자라고 생각한다.
예를 들어 구멍이 하나도 없는 CEFGHIJKLMNSTUVWXYZ들을 같은 문자로 생각하고,
구멍이 한 개 나 있는 ADOPQR들을 같은 문자로 생각하며,
구멍이 두 개 나 있는 유일한 문자 B는 유일하게 정확히 알 수 있다.
알파벳 대문자로 이루어진 두 문자열이 주어졌을 때, 경근이는 두 문자열이 같다고 판별하는지 다르다고 판별할 것인가?

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 문자열이 공백 하나로 구별되어 주어진다.
각 문자열은 알파벳 대문자 만으로 이루어져 있으며, 길이는 10이하이다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
경근이가 주어진 두 문자열을 같은 것으로 생각하면 “SAME”을, 다른 것으로 생각하면 “DIFF”를 출력한다.
*/

/*
CEFGHIJKLMNSTUVWXYZ
ADOPQR
B
같은 것으로 생각하면 “SAME”을, 다른 것으로 생각하면 “DIFF”를 출력
*/

//내 풀이
#include <stdio.h>
#include <string.h>

int main(){
    int T, N, i, j;
    char a[11], b[11];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s %s", &a[0], &b[0]);
        if(strlen(a) != strlen(b)){
            printf("#%d DIFF\n", i);
        }
        else {
            for(j=0; j<strlen(a); j++){
                if(a[j]=='B'){
                    if(b[j]!='B'){
                        printf("#%d DIFF\n", i);
                        break;
                    }
                }
                else if(a[j]=='A' || a[j]=='D' || a[j]=='O' || a[j]=='P' || a[j]=='Q' || a[j]=='R'){
                    if(b[j]!='A' && b[j]!='D' && b[j]!='O' && b[j]!='P' && b[j]!='Q' && b[j]!='R'){
                        printf("#%d DIFF\n", i);
                        break;
                    }
                }
                else {
                    if(b[j]!='C' && b[j]!='E' && b[j]!='F' && b[j]!='G' && b[j]!='H' && b[j]!='I' && b[j]!='J' && b[j]!='K' && b[j]!='L' &&
                    b[j]!='M' && b[j]!='N' && b[j]!='S' && b[j]!='T' && b[j]!='U' && b[j]!='V' && b[j]!='W' && b[j]!='X' && b[j]!='Y' && b[j]!='Z'){
                        printf("#%d DIFF\n", i);
                        break;
                    }
                }
            }
        }
        if(strlen(a)==strlen(b) && j==strlen(a)){
            printf("#%d SAME\n", i);
        }
    }
    return 0;
}

//다른 풀이
#include<stdio.h>
#include<string.h>
 
int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("#%d ", tc);
        char arr[11] = { 0 };
        char brr[11] = { 0 };
        int sarr[11] = { 0 };
        int sbrr[11] = { 0 };
        scanf("%s %s", arr, brr);
        int cnt = 0;
            for (int i = 0; i < strlen(arr); i++) {
                if (arr[i] == 'B') {
                    sarr[i] = 1;
                }
                else if (arr[i] == 'A' || arr[i] == 'D' || arr[i] == 'O' || arr[i] == 'P' || arr[i] == 'Q' || arr[i] == 'R') {
                    sarr[i] = 2;
                }
                else {
                    sarr[i] = 3;
                }
                if (brr[i] == 'B') {
                    sbrr[i] = 1;
                }
                else if (brr[i] == 'A' || brr[i] == 'D' || brr[i] == 'O' || brr[i] == 'P' || brr[i] == 'Q' || brr[i] == 'R') {
                    sbrr[i] = 2;
                }
                else {
                    sbrr[i] = 3;
                }
        }
        for (int i = 0; i < strlen(arr); i++) {
            if (sarr[i] == sbrr[i]) {
                cnt++;
            }
        }
        if (cnt != strlen(arr)||strlen(arr)!=strlen(brr)) {
            printf("DIFF\n");
        }
        else {
            printf("SAME\n");
        }
    }
    return 0;
}