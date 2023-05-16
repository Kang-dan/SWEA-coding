//13547.팔씨름
/*
소정이와 세정이는 점심 값을 누가 낼 지 정하기 위해 팔씨름을 하기로 했다. 공정하고 재밌는 경기를 위해 둘은 15번 팔씨름을 하여 8번 이상 이기는 사람이 점심 값을 면제받기로 하였다.
둘은 지금까지 k번의 팔씨름을 진행했다. 이 결과는 길이가 k인 ‘o’ 또는 ‘x’로만 구성된 문자열 S[1..k]로 나타낼 수 있다. S[i]가 ‘o’면 소정이가 i번째 경기에서 승리했다는 것이고, ‘x’면 패배했다는 것이다.
소정이는 앞으로 팔씨름을 15번째 경기까지 진행했을 때 자신이 점심값을 면제받을 가능성이 있는지 알고자 한다. 이를 대신해 주는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 ‘o’ 또는 ‘x’로만 구성된 길이가 1 이상 15 이하인 문자열 S가 주어진다.

[출력]
각 테스트 케이스마다, 소정이가 점심값을 면제받을 가능성이 있다면 ‘YES’, 없다면 ‘NO’를 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main(void){
    int T, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        //입력
        char k[16]; //C 언어에서 문자열은 NULL 문자('\0')로 끝나야 합니다. 따라서 문자열 배열의 크기는 실제 문자열 길이보다 1 크게 선언되어야함.
        scanf("%s",k);
        int a = 0;
        for(j=0; j<strlen(k); j++){
            if(k[j]=='x') a++;
        }
        if(a<8){
            printf("#%d YES\n", i);
        }
        else{
            printf("#%d NO\n", i);
        }
    }
    return 0;
}

// jin1214님 코드
/*
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    int test_case;
    int T;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
         
        int lose=0;
        bool res=true;
        char str[16];
        scanf(" %s", str);
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='x')lose++;
        }
        lose<8?printf("#%d YES\n", test_case):printf("#%d NO\n", test_case);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
*/