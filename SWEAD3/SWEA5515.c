/* 5515. 2016년 요일 맞추기
2016년 1월 1일은 금요일이었고, 문득 송송이는 특정 날짜의 요일을 맞추고 싶어졌다. 
2016년은 윤년이기 때문에 2월 29일이 포함된다. 2016년 m월 d일은 무슨 요일인지 맞추는 프로그램을 작성하시오.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 정수 m,d가 공백으로 구분되어 주어진다.
m,d는 2016년 m월 d일을 정상적으로 나타낼 수 있는 두 정수이다.

[출력]
각 테스트 케이스마다 2016년 m월 d일이 월요일이면 0, 화요일이면 1, 수요일이면 2, 목요일이면 3, 금요일이면 4, 토요일이면 5, 일요일이면 6을 출력한다.
*/

/* 내 풀이
1. 1월1일부터 요구하는 날짜까지 전체 일수 구하기.
2. 전체 일수를 7로 나눈 나머지 구하기.
3. 1/1일인 금요일부터 나머지만큼 더한 요일이 최종 값!
*/
#include <stdio.h>
int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; //각 월의 일개수
int day[7] = {0,1,2,3,4,5,6}; // 월-일요일. 2016년 1월 1일은 금요일(4)
int main(){
    int T, m, d, i, j;
    int result; // 최종 결과
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d",&m, &d);
        int day_sum = 0; //1월1일부터 m월 d일까지의 총 day 수
        if(m==1){
            day_sum = d-1;
        }
        else if(m>1){
            for(j=0; j<m-1; j++){
                day_sum += month[j];
            }
            day_sum += d-1;
        }
        day_sum %= 7;
        result = (4 + day_sum) % 7; // 최종 요일 구하기

        printf("#%d %d\n", i, result);
    }
    return 0;
}

//다른 풀이
#include<stdio.h>
#include<string.h>
 
int main()
{
    int n, t, a, b, c;
    scanf("%d", &t);
    int arr[12] = { 0,31,60,91,121,152,182,213,244,274,305,335};
    int brr[7] = { 4,5,6,0,1,2,3 };
    for (int tc = 1; tc <= t; tc++) {
        printf("#%d ", tc);
        scanf("%d %d", &a, &b);
        int answer = 0;
        int cnt = 0;
        cnt += arr[a - 1] + b;
        answer = cnt % 7;
        if (answer==0){
            printf("%d\n",brr[6]);
        }
        else{
        printf("%d\n", brr[answer - 1]);
        }
    }
    return 0;
}