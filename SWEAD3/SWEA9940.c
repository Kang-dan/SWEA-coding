//9940.순열1
/*
길이 N의 순열이란, 1부터 N까지의 자연수를 적당한 순서로 섞어서 만든 수열을 의미한다.
예를 들면, (3, 4, 1, 2)는 길이 4의 순열이다.
(2, 3, 4, 4, 5)는 길이가 5이지만 1부터 5까지의 자연수를 적당한 순서로 섞어서 만들 수 없기 때문에 순열이 아니다.
어떤 길이 N의 수열이 주어지면, 이것이 길이 N의 순열인지 판단하여라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
이후 TC개의 테스트 케이스는 각각 다음과 같은 구성과 조건을 따른다.
첫 번째 줄에 주어지는 정수의 개수 N 이 주어진다. (1 ≤ N ≤ 100,000)

다음 줄에는 순열인지 판단해야 할 길이 N의 수열의 원소들이 공백으로 구분되어 주어진다.
주어지는 수열의 원소는 1이상 N이하이다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
각 테스트 케이스마다 이 수열이 순열인 경우 “Yes”를, 아니면 “No”를 출력하여라.
*/

#include <stdio.h>
int main(){
    int T, N, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        int num[100001] = {0};
        for(j=1; j<=N; j++){
            scanf("%d", &num[j]);
        }
        int flag[100001] = {0};
        for(j=1; j<=N; j++){
            flag[num[j]]++;
        }
        int a = 0;
        for(j=1; j<=N; j++){
            if(flag[j]!=1){
                printf("#%d No\n", i);
                break;
            }
        }
        if(j>N) printf("#%d Yes\n", i);
    }
    return 0;
}

//예언가님 코드
/*
#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
    int arr[100000] = { 0 };
        printf("#%d ", tc);
        int n;
        scanf("%d", &n);
        int cnt = 0;
        int a=0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            arr[a]++;
        }
        for (int i = 1; i <= n; i++) {
            if (arr[i] >= 1) {
                cnt++;
            }
        }
        if (cnt == n) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
*/