/* 6190. 정곤이의 단조 증가하는 수
정곤이는 자신이 엄청난 수학자임을 증명하기 위해, 어떤 규칙 만족하는 수를 찾아보기로 했다.
그 규칙은 단조 증가하는 수인데, 각 숫자의 자릿수가 단순하게 증가하는 수를 말한다.
어떤 k자리 수 X = d1d2…dk 가 d1 ≤ d2 ≤ … ≤ dk 를 만족하면 단조 증가하는 수이다.
예를 들어 111566, 233359는 단조 증가하는 수이고, 12343, 999888은 단조 증가하는 수가 아니다.
양의 정수 N 개 A1, …, AN이 주어진다.
 1 ≤ i < j ≤ N 인 두 i, j에 대해, Ai x Aj값이 단조 증가하는 수인 것들을 구하고 그 중의 최댓값을 출력하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1 ≤N ≤ 1,000) 이 주어진다.
두 번째 줄에는 N개의 정수 A1, …, AN(1 ≤ Ai ≤ 30,000) 이 공백 하나로 구분되어 주어진다.

[출력]
각 테스트 케이스마다 단조 증가하는 수인 Ai x Aj중에서 그 최댓값을 출력한다.
만약 Ai x Aj중에서 단조 증가하는 수가 없다면 -1을 출력한다.
*/

//내 풀이
#include <stdio.h>
long long int max = -1;
long long int result = 0;
int tmp[9999999] = {0};
long long int result_a = 0;
long long int A[1001];
int main(){
    int T, N, i, j, z, k;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        for(j=0; j<N; j++){
            scanf("%lld", &A[j]);
        }

        max = -1;
        if(N==1){
            max = A[0];
        }
        else {
            for(j=0; j<N-1; j++){
                for(z=j+1; z<N; z++){
                    if(N>1){
                        result = A[j] * A[z];
                        result_a = result;
                        tmp[0] = result % 10;
                        result /=10;
                }
                    else if(N==1){
                        result = A[j];
                        result_a = result;
                        tmp[0] = result % 10;
                        result /= 10;
                    }
                    if(result>0){
                        for(k=1; result>0; k++){
                            tmp[k] = result%10;
                            if(tmp[k-1] < tmp[k]) break;
                            result/=10;
                        }
                        if(result<=0){
                            if(max < result_a) max = result_a;
                        }
                    }
                    else {
                        if(max < result_a) max = result_a;
                    }

                }
            }
        }
        printf("#%d %lld\n", i, max);
        
    }
    return 0;
}

//다른 풀이
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isDanjo(int n)
{
    while (1)
    {
        int a = n % 10;
        n /= 10;
        if (n % 10 > a) return 0;
        if (n == 0) return 1;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[1010];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        int max = -1;
        for (int a = 0; a < n - 1; a++)
            for (int b = a + 1; b < n; b++)
            {
                if (isDanjo(arr[a] * arr[b]) && arr[a] * arr[b] > max)
                {
                    max = arr[a] * arr[b];
                }
            }
        printf("#%d %d\n", i+1, max);
    }
    return 0;
}