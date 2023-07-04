/* 12712. 파리퇴치3 (사전학습 알고리즘)
N x N 배열 안의 숫자는 해당 영역에 존재하는 파리의 개체 수를 의미한다.
아래는 N=5 의 예이다.

파리 킬러 스프레이를 한 번만 뿌려 최대한 많은 파리를 잡으려고 한다. 스프레이의 노즐이 + 형태로 되어있어, 스프레이는 + 혹은 x 형태로 분사된다. 스프레이를 M의 세기로 분사하면 노즐의 중심이 향한 칸부터 각 방향으로 M칸의 파리를 잡을 수 있다.
다음은 M=3 세기로 스프레이르 분사한 경우 파리가 퇴치되는 칸의 예로, +또는 x 중 하나로 분사된다. 뿌려진 일부가 영역을 벗어나도 상관없다.

한 번에 잡을 수 있는 최대 파리수를 출력하라.

[제약 사항]
1. N 은 5 이상 15 이하이다.
2. M은 2 이상 N 이하이다.
3. 각 영역의 파리 갯수는 30 이하 이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,
다음 N 줄에 걸쳐 N x N 배열이 주어진다.
*/

#include <stdio.h>
int N, M;
int pari[15][15];

int cross_a(int a, int b){ //+ 모양
    int i, sum = pari[a][b]; //총 파리수
    for(i=1; i<M; i++){
        if(b+i<N) sum += pari[a][b+i]; //동
        if(b-i>=0) sum += pari[a][b-i]; //서
        if(a+i<N) sum += pari[a+i][b]; //남
        if(a-i>=0) sum += pari[a-i][b]; //북
    }
    return sum;
}

int cross_b(int a, int b){ //x 모양
    int i, sum = pari[a][b]; //총 파리수
    for(i=1; i<M; i++){
        if(a-i>=0 && b+i<N) sum += pari[a-i][b+i]; // 위 /방향
        if(a-i>=0 && b-i>=0) sum += pari[a-i][b-i]; // 왼 \방향
        if(a+i<N && b-i>=0) sum += pari[a+i][b-i]; // 아래 /방향
        if(a+i<N && b+i<N) sum += pari[a+i][b+i]; // 아래 \방향
    }
    return sum;
}

int main(){
    int T, i, a, b;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N, &M);
        for(a=0; a<N; a++){
            for(b=0; b<N; b++){
                pari[a][b] = 0;
            }
        }
        //파리개수 입력
        for(a=0; a<N; a++){
            for(b=0; b<N; b++){
                scanf("%d", &pari[a][b]);
            }
        }
        //잡을 수 있는 최대 파리수
        int max = 0, A=0, B=0;
        for(a=0; a<N; a++){
            for(b=0; b<N; b++){
                A = cross_a(a,b);
                B = cross_b(a,b);
                if(max<=A && A>=B) max = A;
                else if(max<=B && A<=B) max = B;
            }
        }
        printf("#%d %d\n", i, max);
    }
    return 0;
}