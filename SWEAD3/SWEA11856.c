//11856.반반
/*
길이 4의 알파벳 대문자로 이루어진 문자열 S가 주어졌을 때, S에 정확히 두 개의 서로 다른 문자가 등장하고, 각 문자가 정확히 두 번 등장하는 지 판별하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.
∙ 첫 번째 줄에 문자열 S가 주어진다.

[출력]
각 테스트 케이스마다
∙ 조건이 만족되면 “Yes”, 아니면 “No” 를 출력하라.
*/

#include <stdio.h>
int main(void){
    int T, i, j;
    char S[5];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s", &S[0]); //scanf("%s", S);
        int a=0, b=0, flag=1;
        for(j=1; j<4; j++){
            if(S[0]==S[j]) flag++;
            else{
                if(a!=0) b = j;//2
                else a = j; //1
            }
        }
        if(flag!=2) printf("#%d No\n", i);
        else if(S[a] != S[b]) printf("#%d No\n", i);
        else printf("#%d Yes\n", i);
    }
    return 0;
}

//Chat-GPT3.5
/*
#include <stdio.h>
#include <stdbool.h>

// 문자열 S에 정확히 두 개의 서로 다른 문자가 등장하고, 각 문자가 정확히 두 번 등장하는지 판별하는 함수
bool checkString(char* S) {
    int count[26] = {0};  // 알파벳 대문자 개수를 저장할 배열

    for (int i = 0; i < 4; i++) {
        count[S[i] - 'A']++;  // 문자의 등장 횟수를 증가
    }

    int distinctChars = 0;  // 서로 다른 문자의 개수
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            distinctChars++;  // 등장한 문자 개수 증가
            if (count[i] != 2) {
                return false;  // 등장한 문자가 2번이 아니면 조건 불만족
            }
        }
    }

    return distinctChars == 2;  // 서로 다른 문자가 2개인지 반환
}

int main() {
    int TC, i;
    scanf("%d", &TC);

    for(i=1; i<=TC; i++){
        char S[5];
        scanf("%s", S);

        bool result = checkString(S);

        if (result) {
            printf("#%d Yes\n", i);
        } else {
            printf("#%d No\n", i);
        }
    }

    return 0;
}
*/