//1959.두 개의 숫자열
/*
N 개의 숫자로 구성된 숫자열 Ai (i=1~N) 와 M 개의 숫자로 구성된 숫자열 Bj (j=1~M) 가 있다.
아래는 N =3 인 Ai 와 M = 5 인 Bj 의 예이다.

Ai 나 Bj 를 자유롭게 움직여서 숫자들이 서로 마주보는 위치를 변경할 수 있다.
단, 더 긴 쪽의 양끝을 벗어나서는 안 된다.

서로 마주보는 숫자들을 곱한 뒤 모두 더할 때 최댓값을 구하라.
위 예제의 정답은 아래와 같이 30 이 된다.

[제약 사항]
N 과 M은 3 이상 20 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,
두 번째 줄에는 Ai,
세 번째 줄에는 Bj 가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력예시)
1
3 5
1 5 3
3 6 -7 5 4
출력예시)
#1 30
*/

#include <stdio.h>
int main(){
    int T, N, M, i, j;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N, &M);
        int A[N];
        int B[M];
        //숫자열 생성
        for(j=0; j<N; j++){
            scanf("%d", &A[j]);
        }
        for(j=0; j<M; j++){
            scanf("%d", &B[j]);
        }
        //출력
        int sum;
        int a;
        if(N>=M){ //길이가 A>=B
            int result[N-M+1]; //곱해서 더한값 저장소
            int num = N-M+1;
            a = 0;
            while(num>0){
            sum = 0;
            for(j=0; j<M; j++){
                sum = sum + A[j+a] * B[j];
            }
            result[num-1] = sum;
            a++;
            num--;
            }
            //최댓값 찾기
            int max = result[0];
            for(j=1; j<N-M+1; j++){
                if(max < result[j]) max = result[j];
            }
            printf("#%d %d\n", i, max);
        }

        else { //길이가 A<B
            int result[M-N+1]; //곱해서 더한값 저장소
            int num = M-N+1;
            a = 0;
            while(num>0){
            sum = 0;
            for(j=0; j<N; j++){
                sum = sum + A[j] * B[j+a];
            }
            result[num-1] = sum;
            a++;
            num--;
            }
            //최댓값 찾기
            int max = result[0];
            for(j=1; j<M-N+1; j++){
                if(max < result[j]) max = result[j];
            }
            printf("#%d %d\n", i, max);
        }
    }
    return 0;
}

//kikikiko님 코드
/*
#include <stdio.h>
 
int main()
{
    int tc, t, n, m;
    char a[20];
    char b[20];
    int min_len, max_value;
 
    scanf("%d", &tc);
    for (t = 0; t < tc; t++)
    {
        scanf("%d %d", &n, &m); //그 a,b배열의 갯수
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]); //입력받은 다음에!
 
        int bigger;
        if (n < m)
        {
            min_len = n;
            bigger = m;
        }
        else
        {
            min_len = m;
            bigger = n;
        }
 
        int tmp = 0;
        max_value = -987654321;
        for (int k = 0; k <= bigger - min_len; k++)
        {
            tmp = 0;
            for (int i = 0; i < min_len; i++)
            {
                if (bigger == n)
                    tmp += a[i+k] * b[i];
                else if (bigger == m)
                    tmp += a[i] * b[i+k];
            }
            if (max_value < tmp)
                max_value = tmp;
        }
        printf("#%d %d\n", t + 1, max_value);
    }
    return 0;
 
}
*/