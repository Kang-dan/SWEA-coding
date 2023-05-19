//10912.외로운 문자
/*
알파벳 소문자 만으로 이루어진 문자열이 주어진다.
이 문자열에서 같은 두 문자들을 짝짓고 남는 문자가 무엇인지 구하는 프로그램을 작성하라.
같은 문자를 여러 번 짝지어서는 안 된다.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 알파벳 소문자 만으로 이루어진 문자열이 주어진다.
이 문자열의 길이는 1이상 100이하이다.

[출력]
각 테스트 케이스 마다 예제와 같은 형식으로 남는 문자를 사전 순서대로 출력한다.
만약 어떤 문자도 남지 않는다면 “Good”을 출력하도록 한다.
*/

#include <stdio.h>
#include <string.h>

int main(void){
    int T,i,j;
    char n[101];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s",&n[0]);
        int flag[26] = {0};
        for(j=0; j<strlen(n); j++){
            flag[n[j]-'a']++;
        }
        printf("#%d ",i);
        int count=0;
        for(j=0; j<26; j++){
            if(flag[j]%2==1){
                printf("%c",'a'+j);
            }
            else if(flag[j]%2==0)count++;
        }
        if(count == 26) printf("Good\n");
        else printf("\n");
    }
    return 0;
}

//hwanxyz님 코드
/*
#include <stdio.h>
#include <string.h>
#include <math.h> 
int main(void)
{
    int test_case;
    int T, N,X, Y, i ;
    int fla = 0;
    char arry[100];
    char alpa[26] = {0};
     
     for(i=0;i<26;i++){
        alpa[i]=0;
    }   
 
    scanf("%d", &T);
    /*
    여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {   
         
        scanf("%s",&arry);                                 
        for(i = 0 ; i < strlen(arry) ; i++)
        {
            alpa[arry[i] - 'a']++;
        }         
        int flg = 0;
        printf("#%d ", test_case);
        for(i = 0; i < 26; i++)
        {
            if(alpa[i] !=0)
            {
                if(alpa[i]%2)
                {
                    printf("%c",'a'+i);
                    flg = 1;
                }
                alpa[i]=0;
            }
        }
         
        if(!flg)
            printf("Good") ;
 
        printf("\n") ;
         
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
*/