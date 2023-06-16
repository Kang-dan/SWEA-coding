/*7193. 승현이의 수학공부 (배열선언위치, strlen 사용 유무에 따른 런타임에러 공부)
승현이는 N(2 ≤ N ≤ 10) 진법의 수 X(1 ≤ X ≤ N10,000,000) 를 공책에 적었다.
승현이는 손이 점점 아프기 시작했고, 머릿속에서 문득 X를 (N-1)로 나눈 나머지가 궁금해졌다.
승현이를 도와 N진법의 수 X가 주어졌을 때에 X를 (N-1)로 나눈 나머지를 계산하는 프로그램을 작성하라.
예를 들면, 9진법의 수 234는 10진법으로 193이고, 8로 나눈 나머지는 1이 된다.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수 N, X가 공백 하나로 구분되어 주어진다.
X가 매우 큰 숫자임에 유의하라.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
N진법의 수 X가 주어졌을 때에 X를 (N-1)로 나눈 나머지를 출력한다.
*/

#include <stdio.h>

char X[10000009];
int main(){
    int T, N, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %s", &N, X);
        long long int result = 0;
        for(j=0; j<10000009; j++){
            if(X[j]=='\0') break;
            result += (X[j]-'0');
        }
        result = result % (N-1);
        printf("#%d %lld\n", i, result);
    }
    
    return 0;
}

//이 코드는 런타임 에러남.
#include <stdio.h>
#include <string.h>

char X[10000009];
int main(){
    int T, N, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %s", &N, X);
        long long int result = 0;
        for(j=0; j<strlen(X); j++){
            result += (X[j]-'0');
        }
        result = result % (N-1);
        printf("#%d %lld\n", i, result);
    }
    
    return 0;
}