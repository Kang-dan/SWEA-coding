//9317.석찬이의 받아쓰기
/*
아기 석찬이는 내년에 초등학교에 입학하지만 아직 알파벳을 떼지 못했다.
석찬이의 부모님은 그런 석찬이를 위해 알파벳을 공부할 수 있는 학습지를 구독하였다.
학습지에는 길이 N의 알파벳 대소문자로만 이루어진 문자열이 주어지는데, 석찬이는 대소문자를 제대로 구분해서 이 문자열을 받아 적어야 한다.
석찬이는 N 개의 문자를 받아 적는 데는 성공했지만, 틀리게 적은 문자들이 몇 개 보인다.
석찬이가 몇 개의 문자를 올바르게 받아 적었는지 세어보자.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC 가 주어진다.
이후 TC 개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되어 있다.

첫 번째 줄에 문자열의 길이 N 이 주어진다. (1 ≤ N ≤ 100,000)
두 번째 줄에 석찬이가 따라서 적어야 하는 문자열이 주어진다.
세 번째 줄에 석찬이가 받아 적은 문자열이 주어진다.
두 번째 줄과 세 번째 줄에 주어진 문자열은 모두 알파벳 대소문자로 구성되어 있고,
문자열의 길이는 첫 번째 줄에서 주어진 N 이다.

[출력]
각 테스트 케이스마다 ‘#t ’(t 는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
석찬이가 맞게 받아 적은 문자의 개수를 출력하라. 틀린 개수가 아님에 유의하라.
*/

#include <stdio.h>
int main(){
    int T, N, i, j;
    char a[100001], b[100001];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        scanf("%s", &a[0]);//기존
        scanf("%s", &b[0]);//석찬이
        int count=0;
        for(j=0; j<N; j++){
            if(a[j]==b[j]) count++;
        }
        printf("#%d %d\n", i,count);
    }
    return 0;
}