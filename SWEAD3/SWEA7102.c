/* 7102. 준홍이의 카드놀이
준홍이에게는 카드 두 세트가 있다.
각 카드 세트는 1번 카드부터 N번 카드, 1번 카드부터 M번 카드로 구성되어 있다.
심심했던 준홍이는 각 카드 세트에서 카드 한 장씩을 골랐다.
그리고 각 카드에 적힌 숫자를 더해보았다.
1번 카드와 1번 카드를 골랐다면 카드에 적힌 숫자의 합은 2가 될 것이고, N번 카드와 M번 카드를 골랐다면 카드에 적힌 숫자의 합은 N+M이 될 것이다.
문득 준홍이는 각 카드 세트에서 카드를 한 장씩 골라서 카드에 적힌 숫자를 합한 결과 중, 등장할 확률이 가장 높은 숫자는 어떤 숫자일지 궁금해졌다.
단, 카드 세트에서 어떤 카드를 선택할 확률은 모두 동일하다고 가정한다.
이를 계산하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 개의 x정수 N, M(4 ≤ N, M ≤ 20)이 공백 하나로 구분되어 주어진다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
선택한 두 카드에 적힌 숫자의 합 중 등장할 확률이 가장 높은 것들을 오름차순으로 공백을 사이에 두고 한 줄에 모두 출력한다.

*/
#include <stdio.h>
int main(){
    int T, N, M, i, j, k;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N, &M);
        int num[41] = {0};
        for(j=1; j<=N; j++){
            for(k=1; k<=M; k++){
                num[j+k]++;
            }
        }
        int max = num[1];
        int flag[41] = {0};
        for(j=2; j<=N+M; j++){
            if(num[j]>=max){
                max = num[j];
            }
        }
        printf("#%d", i);
        for(j=1; j<=N+M; j++){
            if(num[j]==max){
                printf(" %d", j);
            }
        }
        printf("\n");
    }
    return 0;
}