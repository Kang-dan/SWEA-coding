//2043.서랍의 비밀번호
/*
서랍의 비밀번호가 생각이 나지 않는다.
비밀번호 P는 000부터 999까지 번호 중의 하나이다.
주어지는 번호 K부터 1씩 증가하며 비밀번호를 확인해 볼 생각이다.
예를 들어 비밀번호 P가 123 이고 주어지는 번호 K가 100 일 때, 100부터 123까지 24번 확인하여 비밀번호를 맞출 수 있다.
P와 K가 주어지면 K부터 시작하여 몇 번 만에 P를 맞출 수 있는지 알아보자.

[입력]
입력으로 P와 K가 빈 칸을 사이로 주어진다.

[출력]
몇 번 만에 비밀번호를 맞출 수 있는지 출력한다.
*/

#include <stdio.h>

int main() {
    int P, K;

    scanf("%d %d", &P, &K);
    while(P>999 || P<0 || K>999 || K<0){
        printf("0부터 999까지의 숫자만 입력할 수 있습니다.\n");
        return 0;
    }

    if (P >= K){
        printf("%d\n", P - K + 1);
    }
    else {
        printf("%d\n", 1001 - K + P);
    }

    printf("P=%03d K=%03d\n", P, K); // 추가로 작성함.
    return 0;
}