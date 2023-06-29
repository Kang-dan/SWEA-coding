/* 5986. 새샘이와 세 소수 (풀이중)
정수론에서, 세 소수 문제란 다음과 같다.
“5보다 큰 모든 홀수는 정확히 세 소수의 합으로 표현될 수 있다. (같은 소수를 합에 사용해도 된다.)”
예를 들어, 7 = 2 + 2 + 3, 11 = 2 + 2 + 7, 25 = 7 + 7 + 11로 나타낼 수 있다.
1939년 러시아 수학자 I. M. Vinogradov는 충분히 큰 홀수는 세 소수의 합으로 표현할 수 있다는 것을 증명했다.
여기서 충분히 크다는 것은 3315 ≈ 107000000 이상의 수라는 의미이다.
현재 가장 발전된 하한은 약 e3100 ≈ 101346 이상의 수이다.
러시아 수학자 I. M. Vinogradov 를 존경하는 새샘이는 직접 세 소수 문제를 풀어보기로 했다.
하지만 이 수는 너무 크기 때문에 컴퓨터로도 이 범위까지의 모든 수를 증명할 수는 없었다.
대신 어떤 크지 않은 홀수에 대해, 세 소수의 합으로 나타낼 수 있는 경우의 수를 구하기로 했다.
5보다 큰 홀수 N을 입력 받아 N = x + y + z (단, x ≤ y ≤ z 이고, x, y, z는 소수) 로 나타나는 경우의 수를 구하는 프로그램을 작성
하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에 하나의 정수 N ( 7 ≤ N ≤ 999 ) 이 주어진다.
N은 홀수이다.

[출력]
각 테스트 케이스마다 첫 번째 줄에는 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
N을 세 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.
*/

//다른 풀이1
#include <stdio.h>
int prime[1000];
int arr[1000], end;
int cnt[1000];
void findPrime(){
    for (int i = 2; i <= 999; i++)
        prime[i] = 1;
  
  
    for (int i = 2; i <= 100; i++)
    {
        if (prime[i]){
            for (int j = i * i; j <= 999; j += i)
                prime[j] = 0;
        }
    }
    for (int i = 2; i <= 999; i++)
    {
        if (prime[i]) arr[end++] = i;
    }
      
    for (int i = 0; i < end - 2; i++)
    {
        for (int j = i; j < end - 1; j++)
        {
            for (int k = j; k < end; k++)
            {
                int t = arr[i] + arr[j] + arr[k];
                if (t > 999)                 
                    break;
  
                cnt[t]++;
            }
        }
    }
}
int main()
{
    findPrime();
    int T; scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        scanf("%d", &N);
  
          
        printf("#%d %d\n", tc, cnt[N]);
    }
    return 0;
}

//다른 풀이2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int gPrimes[1000];  // 168개
int gPrimeCnt;
int gCnt[1000];
 
void InitPrimes() {
    int prime_flag[1000] = { 0 };
    for (int i = 2; i < 1000; i++) {
        for (int j = 2; j < 1000; j++) {
            if (i * j >= 1000) break;
            prime_flag[i * j] = 1;
        }
    }
    gPrimeCnt = 0;
    for (int n = 2; n < 1000; n++) {
        if (!prime_flag[n]) gPrimes[gPrimeCnt++] = n;
    }
}
void PreProcess() {
    for (int i = 0; i < 1000; i++) gCnt[i] = 0;
    for (int i = 0; i < gPrimeCnt; i++) {
        for (int j = i; j < gPrimeCnt; j++) {
            for (int k = j; k < gPrimeCnt; k++) {
                int prime1 = gPrimes[i];
                int prime2 = gPrimes[j];
                int prime3 = gPrimes[k];
                int num = prime1 + prime2 + prime3;
                if (num >= 1000) continue;
                gCnt[num]++;
            }
        }
    }
}
int main() {
    InitPrimes();
    PreProcess();
    int TC, N;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &N);
        printf("#%d %d\n", tc, gCnt[N]);
    }
    return 0;
}

//내 풀이 (1000개 테스트 중 121개 통과 (나머지 시간초과))
#include <stdio.h>

int check(int num){
    int i;
    if(num==2) return 1;
    else
        for(i=2; i*i<=num; i++){
            if(num%i==0) return 0;
        }
    return 1;
}

int main(){
    int T, N, i, j, x, y, z;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        int count = 0;
        for(x=2; x<=N-2; x+=2){
            if(check(x)==0) continue;
            else {
                for(y=x; y<=N-2; y+=2){
                    if(check(y)==0) continue;
                    else {
                        for(z=y; z<=N-4; z+=2){
                            if(check(z)==0){
                                if(z==2) z--;
                                continue;
                            }
                            else {
                                if(N==x+y+z){
                                    count++;
                                    break;
                                }
                                else if(N<x+y+z) break;
                            }
                            if(z==2) z--;
                        }
                        if(N<x+y+y) break;
                        if(y==2) y--;
                    }
                }
                if(N<x+x+x) break;
                if(x==2) x--;
            }
            if(x==2) x--;
        }
        printf("#%d %d\n", i, count);
    }
}