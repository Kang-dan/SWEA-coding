//1989.초심자의 회문 검사
/*
"level" 과 같이 거꾸로 읽어도 제대로 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.
단어를 입력 받아 회문이면 1을 출력하고, 아니라면 0을 출력하는 프로그램을 작성하라.

[제약 사항]
각 단어의 길이는 3 이상 10 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 하나의 단어가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.) */

#include <stdio.h>
#include <string.h>

int main() {
    int T, i, j;
    char text[10];
    char palindrome[10];

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s", text);
        if(strlen(text)<3 || strlen(text)>10){
            printf("단어는 3 이상 10 이하의 길이로 입력해주세요.\n");
            return 1;
        }
        int a = 0;
        for(j=strlen(text)-1; j>=0; j--){
            if(text[j] != text[strlen(text)-1-j]){
                printf("#%d 0\n", i); //회문 아님
                break;
            }
            else a++;
        }
        if(a == strlen(text)){
            printf("#%d 1\n", i); //회문 맞음
        }
    }
    return 0;
}

//chat GPT
/*
#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) { // 회문인지 확인하는 함수
    int len = strlen(str);
    for(int i=0; i<len/2; i++) { // 처음부터 중간까지 반복문 실행
        if(str[i] != str[len-i-1]) // 대칭되는 문자가 서로 다르면 회문이 아님
            return 0;
    }
    return 1; // 회문일 경우 1 반환
}

int main() {
    int T; // 테스트 케이스 개수
    scanf("%d", &T);

    for(int i=1; i<=T; i++) {
        char str[11]; // 단어를 저장할 배열
        scanf("%s", str);
        printf("#%d %d\n", i, is_palindrome(str));
    }

    return 0;
}
*/