//2047.신문 헤드라인
/*
신문의 헤드라인을 편집하기 위해, 주어지는 문자열의 알파벳 소문자를 모두 대문자로 바꾸는 프로그램을 개발 중이다.
입력으로 주어진 문장에 모든 소문자 알파벳을 찾아 대문자로 변환한 다음, 그 결과를 출력하는 프로그램을 작성하라.

[예제 풀이]
The_headline_is_the_text_indicating_the_nature_of_the_article_below_it.
위와 같은 문자열이 입력으로 주어졌을 때, 출력은 다음과 같다.
THE_HEADLINE_IS_THE_TEXT_INDICATING_THE_NATURE_OF_THE_ARTICLE_BELOW_IT.

[제약 사항]
문자열의 최대 길이는 80 bytes 이다.

[입력]
입력으로 80 bytes 이하의 길이를 가진 문자열이 주어진다.

[출력]
문자열의 소문자를 모두 대문자로 변경한 결과를 출력한다.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char alpa[80];
    int i;

    scanf("%s", &alpa);
    if(strlen(alpa) > 80){
        printf("문자의 길이가 80자가 넘습니다. 80자 이내로 입력해주세요.\n");
        return 0;
    }
    for(i=0; i<80; i++){
        if(alpa[i] >= 'a'){
            alpa[i] = alpa[i] - 32;
        }
    }
    printf("%s\n", alpa);

    return 0;
}

//ICYOU 님이 작성한 C++코드
/*
#include <cstdio> //이건 C++ 헤더파일임
char s[80];
 
int main()
{
    int i = 0;
    scanf("%s", s);
 
    while (s[i] != 0) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i++] -= 32;
        else i++;
    }
    printf("%s", s);
}
*/

//챗 GPT
/*
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 80

int main() {
    char alpa[MAX_LENGTH + 1];  // '\0'을 포함하여 80글자 이상 입력받을 수 없도록 하기 위해 +1
    int i;

    printf("문자열을 입력하세요 (80자 이내): ");
    scanf("%80s", alpa);  // 최대 80글자만 입력받도록 제한

    for(i = 0; alpa[i] != '\0'; i++){
        alpa[i] = toupper(alpa[i]);
    }

    printf("입력한 문자열의 대문자 변환 결과: %s\n", alpa);

    return 0;
}
/*