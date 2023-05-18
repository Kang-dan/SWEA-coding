//11688.Calkin-Wilf tree 1
/*
Calkin-Wilf tree는 모든 양의 유리수를 정확히 하나씩 포함하고 있는 트리다. 이 트리는 다음과 같이 정의된다
∙ 트리의 루트는 1/1 을 나타낸다.
∙ 트리의 각 노드는 왼쪽 자식과 오른쪽 자식을 가지는데 어떤 노드가 a/b 를 나타내고 있다면, 왼쪽 자식은 a/a+b 를 오른쪽 자식은 a+b/b 를 나타낸다.
루트 노드에서부터, 자식을 따라 내려간 방향이 순서대로 주어질 때, 마지막에 위치한 노드가 어떤 유리수를 나타내는지 구하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 길이 1이상 30이하인 문자열이 주어진다. 이 문자열은 ‘L’또는 ‘R’로만 이루어져 있으며, i번째 문자가 ‘L’이면 i번째로 이동할 때 현재 노드에서 왼쪽으로, ‘R’이면 i번째로 이동할 때 현재 노드에서 오른쪽으로 내려갔음을 의미한다. 

[출력]
각 테스트 케이스마다 주어진 문자열을 따라 이동을 끝냈을 때, 위치한 노드가 나타내는 유리수가 기약분수로 a/b 이면 a와 b를 공백 하나로 구분하여 출력한다.
*/

#include <stdio.h>
#include <string.h>
int main(void){
    int T, i, j;
    char N[30] = {'0'};
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s", &N[0]);
        int a=1, b=1;
        for(j=0; j<strlen(N); j++){
            if(N[j] == 'L'){
                a = a;
                b = a+b;
            }
            else if(N[j] == 'R'){
                a = a+b;
                b = b;
            }
        }
        printf("#%d %d %d\n", i, a,b);
    }
    return 0;
}

//다빈치코드님 코드
/*
#include<stdio.h>
#include<string.h>
 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        gcd(b, a % b);
}
 
int main() {
 
    int t;
    char s[50];
    long arr_a[10001], arr_b[10001];
    scanf("%d", &t);
 
    for (int i = 0; i < t; i++) {
        scanf("%s", s);
        int len = strlen(s);
        int a = 1;
        int b = 1;
        for (int j = 0; j < len; j++) {
            if (s[j] == 'L') {
                b = a + b;
            }
            else
                a = a + b;
        }
        int gcd_value = gcd(a, b);
        arr_a[i] = a / gcd_value;
        arr_b[i] = b / gcd_value;
    }
 
    for (int i = 0; i < t; i++) {
        printf("#%d %ld %ld\n", i + 1, arr_a[i], arr_b[i]);
    }
    return 0;
 }
 */