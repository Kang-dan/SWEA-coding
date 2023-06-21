/* 6718. 희성이의 원근법
어느날 희성이는 멀리 있는 물체는 보기가 힘들다는 생각을 했다.
그렇기에 다음과 같은 방식으로 물체가 얼마나 떨어져 있는지에 따라 다음처럼 수치를 매기기로 했다.
1. 0.1km 미만 : 0으로 매긴다.
2. 0.1km 이상 1km 미만 : 1으로 매긴다.
3. 1km 이상 10km 미만 : 2로 매긴다.
4. 10km 이상 100km 미만 : 3으로 매긴다.
5. 100km 이상 1000km 미만 : 4로 매긴다.
6. 1000km 이상 : 5로 매긴다.
어떤 물체와의 거리가 주어질 때, 위의 방식으로 수치를 매기는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 하나의 정수 이 주어진다.
d는 어떤 물체와의 거리를 m단위로 표현한 수이다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고 한 칸을 띄운 후,
거리에 따른 수치를 출력한다.
*/

//내 풀이
#include <stdio.h>
int main(){
    int T, i, j;
    long long int d;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%lld", &d);
        if(d<100) printf("#%d 0\n", i);
        else if(100<=d && d<1000) printf("#%d 1\n", i);
        else if(1000<=d && d<10000) printf("#%d 2\n", i);
        else if(10000<=d && d<100000) printf("#%d 3\n", i);
        else if(100000<=d && d<1000000) printf("#%d 4\n", i);
        else printf("#%d 5\n", i);
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
        char arr[1000] = { 0 };
        printf("#%d ", tc);
        scanf("%s", arr);
        int len = strlen(arr);
        if (len < 3) {
            printf("0\n");
        }
        else if (len >= 3&&len<4) {
            printf("1\n");
        }
        else if (len>=4&& len < 5) {
            printf("2\n");
        }
        else if (len>=5&&len < 6) {
            printf("3\n");
        }
        else if (len>=6&&len < 7) {
            printf("4\n");
        }
        else {
            printf("5\n");
        }
 
    }
}