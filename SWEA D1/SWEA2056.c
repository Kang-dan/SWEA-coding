//2056.연월일 달력 (틀림.) => printf("%04d", year); 이건 출력될 숫자가 4자리 숫자보다 작으면 앞에 0을 채우라는 뜻!! 이것만 알면 한번에 맞았음.
/*
연월일 순으로 구성된 8자리의 날짜가 입력으로 주어진다.
해당 날짜의 유효성을 판단한 후, 날짜가 유효하다면
[그림1] 과 같이 ”YYYY/MM/DD”형식으로 출력하고,
날짜가 유효하지 않을 경우, -1 을 출력하는 프로그램을 작성하라.

연월일로 구성된 입력에서 월은 1~12 사이 값을 가져야 하며
일은 [표1] 과 같이, 1일 ~ 각각의 달에 해당하는 날짜까지의 값을 가질 수 있다.
※ 2월의 경우, 28일인 경우만 고려한다. (윤년은 고려하지 않는다.)

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include <stdio.h>

int main() {
    int T, i, num;
    int year, month, day;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
            scanf("%d", &num);

        year = num/10000;
        month = (num%10000)/100;
        day = (num%10000)%100;

        if (month<1 || month>12){
            printf("#%d -1\n", i);
        }
        else if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && day<01 || day>31){
            printf("#%d -1\n",i);
        }
        else if ((month==4 || month==6 || month==9 || month==11) && day<1 || day>30){
            printf("#%d -1\n",i);
        }
        else if ((month == 2) && day<1 || day>28){
            printf("#%d -1\n",i);
        }
        else {
            printf("#%d %04d/%02d/%02d\n", i, year, month, day);
        }
    }
    return 0;
}