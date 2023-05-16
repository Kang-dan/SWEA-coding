//13229.일요일 (문자열 비교는 strcmp(문자열1,문자열2)== 0 이면 동일) <string.h>헤더파일 추가하기!
/*
오늘의 요일을 나타내는 문자열 S가 주어진다. S는 “MON”(월), “TUE”(화), “WED”(수), “THU”(목), “FRI”(금), “SAT”(토), “SUN”(일) 중 하나이다.
다음 (즉, 내일 이후의 가장 빠른) 일요일까지는 며칠 남았을까?
 
[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 문자열 S가 주어진다.

[출력]
각 테스트 케이스마다, 다음 일요일까지 며칠 남았는지를 한 줄에 하나씩 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main(void){
    int T, i, j;
    char D[8][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char S[4];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s", S);
        if(strcmp(S,"SUN") == 0){
            printf("#%d 7\n", i);
        }
        else{
           for(j=0; j<7; j++){
               if(strcmp(S, D[j]) == 0) break;
           }
           int a = 0;
           for(j=j+1; j<7; j++){
               if(strcmp(D[j], "SUN") == 0){
                   a++;
                   printf("#%d %d\n", i, a);
                   break;
               }
               a++;
           }
        }
    }
    return 0;
}

//김승진님 코드
/*
#include <stdio.h>
#include <string.h>
 int main()
{
     char st[10];
     int n,i;
     scanf("%d",&n);
     getchar();
     for (i = 0; i < n; i++)
     {
         scanf("%s", st);
         if (strcmp(st, "SUN") == 0) { printf("#%d 7\n", i + 1); }
         else if (strcmp(st, "SAT") == 0) { printf("#%d 1\n", i + 1); }
         else if (strcmp(st, "FRI") == 0) { printf("#%d 2\n", i + 1); }
         else if (strcmp(st, "THU") == 0) { printf("#%d 3\n", i + 1); }
         else if (strcmp(st, "WED") == 0) { printf("#%d 4\n", i + 1); }
         else if (strcmp(st, "TUE") == 0) { printf("#%d 5\n", i + 1); }
         else if (strcmp(st, "MON") == 0) { printf("#%d 6\n", i + 1); }
     }
     return 0;
 }
 */