/*8741. 두문자어
이번 여름 휴가로 하와이를 갈 예정인 상길이는 매일 영어 단어를 외운다.
똑똑한 상길이는 이전에 외운 단어는 단어의 앞글자만 보면 다시 기억해낼 수 있다.
상길이는 자신이 외운 영어 단어를 까먹을 때를 대비해서 단어의 앞글자를 따와 대문자로 적어 놓으려고 한다.
상길이를 도와 세 단어의 앞글자를 따와서 대문자로 바꾸는 프로그램을 작성해보자.
예를 들어 “knuth morris pratt”은 “KMP”로 바뀐다.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 영어 소문자로 이루어진 세 문자열이 주어진다.
각 문자열의 길이는 1이상 20이하이다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
각 테스트 케이스 마다 입력으로 주어진 문자열의 앞글자를 대문자로 바꿔 순서대로 출력한다.
*/
// 방법 1
#include <stdio.h>
int main(){
    int T, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        char s1[21], s2[20], s3[20];
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s3);
        printf("#%d %c%c%c\n", i, s1[0]-32, s2[0]-32, s3[0]-32);
    }
    return 0;
}

//방법 2
/*
#include <stdio.h>
int main(){
    int T, i, j;
    scanf("%d", &T);
    char s1[21];
    for(i=1; i<=T; i++){
        printf("#%d ", i);
        for(j=0; j<3; j++){
            scanf("%s", s1);
            printf("%c", s1[0]-32);
        }
        printf("\n");
    }
    return 0;
} 
*/