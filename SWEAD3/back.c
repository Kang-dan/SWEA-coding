/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX 10000

int visited[MAX_SIZE];
int visit_bfs[MAX];
int graph[MAX_SIZE][MAX_SIZE];

void dfs(int V, int N){
    int i;

    visited[V] = 1;
    printf("%d ", V);
    for(i=1; i<=N; i++){
        if(graph[V][i]==1 && !visited[i]){
            dfs(i, N);
        }
    }
}

void bfs(int V, int N){
    int i;

    visit_bfs[V]=1;
    printf("%d ", V);
    for(i=1; i<=N; i++){
        if(graph[V][i]==1 && !visit_bfs[i]){
            visit_bfs[i] = 1;
            printf("%d ", i);
        }
    }
    for(i=1; i<=N; i++){
        if(!visit_bfs[i]) bfs(i, N);
    }
}

int main(){
    int N,M,V, i, j;
    scanf("%d %d %d", &N, &M, &V);
    int a, b;
    for(i=1; i<=M; i++){ //간선 연결
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }

    dfs(V, N);
    printf("\n");
    bfs(V, N);
    printf("\n");
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 1000

// int visited[MAX_SIZE];
// int graph[MAX_SIZE][MAX_SIZE];

// void dfs(int v, int n) {
//     int i;
//     visited[v] = 1;
//     printf("%d ", v);
//     for (i = 1; i <= n; i++)
//         if (graph[v][i] && !visited[i])
//             dfs(i, n);
// }

// int main() {
//     int n, m, v, i, j, k;

//     scanf("%d %d %d", &n, &m, &v);

//     for (i = 1; i <= m; i++) {
//         scanf("%d %d", &j, &k);
//         graph[j][k] = graph[k][j] = 1;
//     }

//     dfs(v, n);

//     return 0;
// }

