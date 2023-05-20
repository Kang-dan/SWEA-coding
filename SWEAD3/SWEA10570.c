//10570.제곱 팰린드롬 수
/*
앞으로 읽어도 뒤로 읽어도 똑같은 문자열을 팰린드롬 혹은 회문이라고 부른다. 어떠한 실수 N이 양의 정수이며, 십진수로 표현했을 때 팰린드롬이면 이 수를 팰린드롬 수라고 부른다.
어떠한 양의 정수 N에 대해서, N과 √N이 모두 팰린드롬이면 이 수를 제곱 팰린드롬 수 라고 부른다.
예를 들어, 121은 제곱 팰린드롬 수인데, 121이 팰린드롬이며, 121의 제곱근인 11 역시 팰린드롬이기 때문이다.

A 이상 B 이하 제곱 팰린드롬 수는 모두 몇 개인가?

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스의 첫 번째 줄에 A, B 가 주어진다. (1 ≤ A ≤ B ≤ 1000)

[출력]
각 테스트 케이스 마다 한 줄씩, 제곱 팰린드롬 수의 개수를 출력하라.
*/

#include <stdio.h>

int check(int j){ //회문인지
    int tmp=j;
    int a=0;
    while(tmp>0){
        a = a*10 + tmp%10;
        tmp/=10;
    }
    if(a==j) return 1;
    else return 0;
}

int main(){
    int T, A, B, i, j, k;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &A, &B);
        int num = 0;
        for(j=A; j<=B; j++){
            if(check(j)){
                //제곱 회문인지
                for(k=1; k<=j; k++){
                    if(k*k == j){
                        //k도 회문인지
                        if(check(k)) num++;
                    }
                }
            }
        }
        printf("#%d %d\n", i, num);
    }
    return 0;
}

//예언가님 코드
/*
#include<stdio.h>
 
int main()
{
    int t,a,b;
    int c, d,e;
    char arr[30] = { 0, };
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("#%d ", tc);
        scanf("%d %d",&a,&b);
        int answer = 0;
        for (int i = a; i <= b; i++) {
            if (i < 10) {
                for(int j =1; j<10; j++){
                        if(j*j==i) answer++;
            }
            }
            else if (i > 100 && i < 1000) {
                c = i / 100;
                e = i % 10 %10;
                if (c == e) {
                    for(int j =1; j<100; j++){
                        if(j*j==i){
                            c=j/10;
                            d=j%10;
                            if(c==d) answer++;
                        }
                    }
                }
            }
            else if (i >10 && i < 100) {
                c = i / 10;
                d = i % 10;
                if (c == d ) {
                    for(int j =1; j<100; j++){
                        if(j*j==i){
                            c=j/10;
                            d=j%10;
                            if(c==d) answer++;
                        }
                    }
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
*/