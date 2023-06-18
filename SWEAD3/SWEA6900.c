/* 6900. 주혁이의 복권 당첨
대박을 꿈꾸는 주혁이는 오늘 복권을 M장 구매했다.
각 복권에는 8자리의 고유 번호가 붙어 있다.
이 복권에는 여러 당첨 번호가 있어서 역시 8자리로 ‘*’혹은 숫자로 이루어져 있다.
복권의 고유 번호와 당첨 번호가 매치되면 당첨 번호에 따라 당첨금이 지급된다. ‘*’는 모는 숫자와 매치될 수 있다.
예를 들어 소지한 복권의 번호가 “20170101”인 경우, “***7****”이나 “2017****”같은 당첨 번호와는 매치가 되지만,
“2016****”같은 당첨번호에는 매치되지 않는다.
이 복권의 모든 당첨 번호는 여러 복권이 당첨되지 않도록 설정되어 있다.
예를 들어 당첨 번호가 “***7****”, “2017****”인 경우는 없는 것이다. 왜냐하면 “20170101”가 둘 모두에 매치되기 때문이다.
복권의 당첨 번호 N개와 주혁이가 가진 복권 M개의 고유 번호가 주어질 때 주혁이가 얻을 수 있는 당첨금은 얼마인지 구해보자.

[입력]
첫 번째 줄에 테스트 케이스의 수 T   가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수  이 공백으로 구분되어 주어진다.
다음 N 개의 줄의 각 줄에는 8자리의 당첨 번호와 이 당첨 번호에 매치될 때 얻을 수 있는 당첨금을 나타내는 정수 이 주어진다.
당첨 번호는 ‘*’와 숫자만으로 이루어진 문자열이다.
다음 M 개의 줄에는 주혁이가 구매한 복권의 고유 번호를 나타내는 8자리 문자열이 주어진다. 이 문자열은 숫자만으로 이루어져 있다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고 주혁이가 얻을 수 있는 당첨금의 총합을 출력한다.
*/

#include <stdio.h>
int main(){
    int T, N, M, i, j, k, z;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        //당첨번호 N개, 각 해당되는 당첨금 a_m, 구매한 복권번호 M개
        scanf("%d %d", &N, &M);
        char a[N+1][9];
        long long int a_m[N+1];
        for(j=0; j<N; j++){
            scanf("%s %lld", &a[j][0], &a_m[j]);
        }
        char b[M+1][9];
        for(j=0; j<M; j++){
            scanf("%s", &b[j][0]);
        }
        //매치확인
        long long int sum = 0;
        for(j=0; j<M; j++){
            for(k=0; k<N; k++){
                for(z=0; z<8; z++){
                    if(a[k][z]=='*') continue;
                    else if(a[k][z]!=b[j][z]) break;
                }
                if(z==8){
                    sum+= a_m[k];
                    break;
                }
            }
        }
        printf("#%d %lld\n", i, sum);

    }
    return 0;
}