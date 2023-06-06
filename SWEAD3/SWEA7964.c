/* 7964. 부먹왕국의 차원 관문 (배열을 동적으로 할당하기)
부먹 왕국은 찍먹 무리에게 침략을 당했었다.
하지만 탕수육의 힘으로 성공적으로 막아 내었으나 도시의 많은 차원관문이 파괴당했다.
부먹 왕국의 특징은 모든 도시들을 건설 할 때 일렬로 이어지게 만들었다.
어느 도시에 차원 관문을 설치하면 그 도시와 거리 D 이하인 다른 도시에서 차원 관문이 있는 곳으로 들어오거나, 혹은 차원 관문에서 거리 D 이하인 다른 도시로 나가는것이 가능하다.

찍먹 왕국의 재침공에 대비하기 위해서 모든 도시 이동이 되어야하며 모든 차원 관문 사이와 직접적으로 이동이 가능하도록 차원 관문을 재건하려고 한다.
(단, 0번 위치와 N+1번 위치에는 차원 관문이 존재 한다.)
가능한 빠른 건설을 위하여 최소 개수로 설치하는 계획을 세우려고 할때
도시들마다 차원관문이 남아있는 지에 대한 정보가 주어졌을 때, 이동에 필요한 차원관문의 최소 개수를 구하여라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 부먹 왕국의 도시 수 N(1 ≤ N ≤ 300,000)과 이동 제한 거리 D(1 ≤ D ≤ N)이 주어진다.
두 번째 줄에는 1번 도시부터 차례대로 각 도시에 차원관문이 남아있는 지에 대한 정보가 주어진다.
1은 남아있음을 의미하며 0은 파괴 당한 것을 의미한다.
i번 도시와 (i+1)번 도시 사이의 거리는 모든 1 ≤ i < N에 대해서 1이다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
각 테스트 케이스마다 부먹 왕국이 추가로 건설 해야 하는 차원관문 의 최소 개수를 구하여라.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, i, j;
    long long int N, D;
    scanf("%d", &T);
    
    for(i = 1; i <= T; i++) {
        scanf("%lld %lld", &N, &D);
        int* num = (int*)malloc(N * sizeof(int));
        
        for(j = 0; j < N; j++) {
            scanf("%d", &num[j]);
        }
        
        long long int count = 0;
        long long int result = 0;
        
        for(j = 0; j < N; j++) {
            if(num[j] == 1) count = 0;
            else if(num[j] == 0) count++;
            
            if(count == D) {
                result++;
                count = 0;
            }
        }
        
        printf("#%d %lld\n", i, result);
        
        free(num); // 동적으로 할당한 메모리 해제
    }
    
    return 0;
}

//아래 코드로하면 런타임 에러가 남.
#include <stdio.h>

// int num[300001]; 여기에 배열을 선언해주면 통과!
int main(){
    int T, i, j, k;
    long long int N, D;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%lld %lld", &N, &D);
        int num[N+1]; //여기에 배열선언하면 런타임 에러남.!!
        for(j=0; j<N; j++){
            scanf("%d", &num[j]); //0아니면 1
        }
 
        long long int count = 0;
        long long int result = 0;
        for(j=0; j<N; j++){
            if(num[j] == 1) count = 0;
            else if(num[j] == 0) count++;
            if(count == D){
                result++;
                count = 0;
            }
        }
        printf("#%d %lld\n", i, result);
    }
    return 0;
}

/* 예언가님 코드
#include<stdio.h>
#include<string.h>
 
int arr[300000] = { 0 };
int main()
{
    int n, t, k, m;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("#%d ", tc);
        scanf("%d %d", &n, &m);
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                cnt++;
            }
            else if (arr[i] == 1) {
                cnt = 0;
            }
            if (cnt == m) {
                answer++;
                cnt = 0;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
*/