/* DFS는 주로 다음과 같은 상황에서 활용

1.그래프의 모든 정점을 탐색하고자 할 때
2.그래프에서 경로 탐색이 필요한 경우
3.그래프에서 사이클을 찾고자 할 때
4.그래프의 연결 여부를 확인하고자 할 때
5.백트래킹(backtracking) 문제를 해결할 때
*/

/* 7227. 사랑의 카운슬러 (다시 풀어보기)
오훈이에게는 지렁이 친구 N마리가 있다. 오훈이는 지렁이들을 위해 소개팅을 주선하고자 한다.
주선 방법은 임의의 지렁이 두 마리를 매칭시킨 후 한 지렁이에게 다른 지렁이가 있는 곳으로 가도록 하는 것이다.
이 때, 수학을 좋아하는 오훈이는 가능한 지렁이들이 움직인 벡터 합의 크기가 작기를 바란다.
지렁이들은 2차원 평면 안에서 꿈틀거리고 있는데,
지렁이들이 움직인 벡터를 나타내는 방법은 점 A 위에 있는 지렁이가 점 B 위에 있는 지렁이에게 갔다면,
그 벡터는 점 A에서 점 B를 가리키는 벡터가 된다.
벡터 V=(x, y)의 크기는 다음과 같이 정의하자.

│V│=│(x, y)│= x * x + y * y

모든 지렁이들을 매칭시키고 소개팅을 주선하되, 각 지렁이들이 움직인 벡터를 합하여 그 크기가 최소가 되도록 하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 정수 N(2 ≤ N ≤ 20, N은 짝수) 가 주어진다.
두 번째 줄 N개의 줄에는 지렁이들이 존재하는 점의 좌표가 주어진다.
모든 좌표 값은 절대값이 100,000보다 작거나 같은 정수다. 지렁이들은 모두 서로 다른 위치에 있다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
지렁이의 움직인 벡터의 합의 크기의 최소값을 출력하라.
*/

#include <stdio.h>

int arr[21][2]; //좌표 저장하는 배열
int N; //점의 개수
int visit[21]; //점의 방문여부
long long min; //최소거리 제곱합 저장
long long x, y, ans;

void dfs(int start, int depth){ //depth는 현재까지 선택한 점의 개수
    if(N/2 == depth){ //첫 번째 그룹에 N/2개의 점이 선택되면 두 번째 그룹에 나머지 점들이 속하게됨.
        x = y = ans = 0;
        for(int i=0; i<N; i++){
            if(visit[i]){ //점이 첫 번째 그룹에 속하면 x와 y에 좌표를 더함.
                x+= arr[i][0];
                y+= arr[i][1];
            }
            else { //두 번째 그룹에 속하면 x와 y에서 좌표를 뺌.
                x-=arr[i][0];
                y-=arr[i][1];
            }
        }
        ans= x*x + y*y;
        if(min>ans) min = ans;
        return;
    }
    for(int i=start; i<N; i++){ //현재 위치부터 남은 점들에 대해 반복.
        if(visit[i]==0){
            visit[i]=1;
            dfs(i, depth+1);
            visit[i]=0;
        }
    }
}

int main(){
    int T, i, j;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        for(j=0; j<N; j++){
            scanf("%d %d", &arr[j][0], &arr[j][1]);
        }
        min = 1e18; //1e18은 아주 큰 값으로 초기화.
        dfs(0,0); //그룹 나누기를 시작. 초기에는 아무 점도 선택되지 않은 상태이므로 start와 depth를 0으로 전달

        printf("#%d %lld\n", i, min);
    }

    return 0;
}