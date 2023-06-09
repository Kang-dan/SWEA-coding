//1948.날짜 계산기
/*
월 일로 이루어진 날짜를 2개 입력 받아, 두 번째 날짜가 첫 번째 날짜의 며칠째인지 출력하는 프로그램을 작성하라.

[제약 사항]
월은 1 이상 12 이하의 정수이다. 각 달의 마지막 날짜는 다음과 같다.
1/31, 2/28, 3/31, 4/30, 5/31, 6/30, 7/31, 8/31, 9/30, 10/31, 11/30, 12/31
두 번째 날짜가 첫 번째 날짜보다 항상 크게 주어진다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 4개의 수가 주어진다.
첫 번째 수가 월을 나타내고 두 번째 수가 일을 나타낸다. 그 다음 같은 형식으로 두 번째 날짜가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다. (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

//Chat-GPT3.5
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int month1, day1, month2, day2;
        scanf("%d %d %d %d", &month1, &day1, &month2, &day2);
        
        int days = day2 - day1;
        for (int m = month1; m < month2; m++) {
            if (m == 2) {
                days += 28; // 2월은 28일까지 있음
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                days += 30; // 4, 6, 9, 11월은 30일까지 있음
            } else {
                days += 31; // 나머지 달은 31일까지 있음
            }
        }
        
        printf("#%d %d\n", i, days);
    }
    
    return 0;
}

//내 코드
/*
#include <stdio.h>
int main() {
    int T, m1, d1, m2, d2;
    int i;

// 1/31, 2/28, 3/31, 4/30, 5/31, 6/30, 7/31, 8/31, 9/30, 10/31, 11/30, 12/31
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d %d", &m1,&d1,&m2,&d2);

        if(m1 == m2){
            printf("#%d %d\n",i, d2-d1+1);
        }
        else { //m1 < m2
        int a;
            if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12){
                a = 31-d1+1 + d2;
                m1++;
            }
            else if(m1==2){
                a = 28-d1+1 + d2;
                m1++;
            }
            else{
                a = 30-d1+1 + d2;
                m1++;
            }

            while(m1<m2){
                if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12){
                    a += 31;
                    m1++;
                }
                else if(m1==2){
                    a += 28;
                    m1++;
                }
                else{
                    a += 30;
                    m1++;
                }
            }
            printf("#%d %d\n", i, a);
        }
    }
    return 0;
}
*/