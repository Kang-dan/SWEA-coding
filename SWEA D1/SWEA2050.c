//2050.알파벳을 숫자로 변환 (틀림. 문자열길이(strlen()이랑 문자열은 c(문자)가 아니고, s(문자열)인거!))
/*
알파벳으로 이루어진 문자열을 입력 받아 각 알파벳을 1부터 26까지의 숫자로 변환하여 출력하라.

[제약 사항]
문자열의 최대 길이는 200이다.

[입력]
알파벳으로 이루어진 문자열이 주어진다.

[출력]
각 알파벳을 숫자로 변환한 결과값을 빈 칸을 두고 출력한다.
*/
 
#include <stdio.h>
#include <string.h>

int main() {
    char alpabet[200];
    int i;

    scanf("%s", &alpabet);
    if(strlen(alpabet) > 200){
        printf("문자 길이가 너무 깁니다. 200자 내로 입력해주세요\n");
        return 0;
    }

    for(i=0; i<200; i++){
         if (alpabet[i] == 0){
            break;
        }
        printf("%d ", alpabet[i] - 64);
    }
    printf("\n");

    return 0;
}

//챗 GPT 답
/*
#include <stdio.h>
#include <string.h>

#define MAX_LEN 201   // 입력받을 문자열의 최대 길이

int main() {
    char str[MAX_LEN];  // 입력받을 문자열
    int len;            // 문자열의 길이
    int i;              // 반복문에서 사용할 변수

    printf("알파벳 문자열을 입력하세요: ");
    scanf("%s", str);   // 문자열을 입력받음

    len = strlen(str);  // 문자열의 길이를 구함

    printf("변환 결과: ");
    for (i = 0; i < len; i++) {
        printf("%d ", str[i] - 'a' + 1);
    }
    printf("\n");

    return 0;
}
*/