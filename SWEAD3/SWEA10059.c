//10059.유효기간
/*
카드 유효기간은 대개 월(01에서 12)과 년도 뒤 두자리(2021년이면 21)의 순서대로 나타나는데, 예를 들어 2021년 7월은 0721로 나타낸다.
그러나 가끔 년, 월 순서대로, 2107을 유효기간으로 표시하는 곳도 있다. 이 때, 전자를 MMYY표기, 후자를 YYMM표기라고 하자.

21은 1월에서 12월일 수 없기 때문에 0721은 MMYY표기라는 것을 알 수 있다.
하지만 2007년 5월을 예로 들었다면, 어떤 사람들은 이 날의 MMYY표기 0507를 YYMM표기로 받아들여 2005년 7월이라고 해석할 수 있다.

어떤 유효기간 표기 네 자리가 주어질 때, 이 유효기간이 어떤 표기로 나타낸 기간인지 판별하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 가 주어진다. 각 테스트 케이스의 첫 번째 줄에는 네 자리 아라비아 숫자로 이루어진 문자열이 주어진다.

[출력]
각 테스트 케이스마다 주어진 표기가 MMYY표기와 YYMM표기가 둘 다 될 수 있다면 “AMBIGUOUS”를, MMYY표기만 될 수 있다면 “MMYY”를, YYMM표기만 될 수 있다면 “YYMM”을, 둘 중 어떤 표기로도 나올 수 없다면 “NA”를 출력하라.
*/
#include <stdio.h>
int main(void){
    int T, i;
    int D;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &D);
        int a = D/100;//앞 두자리
        int b = D%100;//뒤 두자리
        //MMYY
        if((a>0 && a<=12) && (b>12 || b==0)) printf("#%d MMYY\n", i);
        //YYMM
        else if((a>12 || a==0) && (b>0 && b<=12)) printf("#%d YYMM\n", i);
        //AMBIGUOUS
        else if((a>0 && a<=12) && (b>0 && b<=12)) printf("#%d AMBIGUOUS\n", i);
        //NA
        else printf("#%d NA\n", i);
    }
    return 0;
}

//black4758님 코드
/*
#include <stdio.h>
  
int main(void)
{
    int T = 0, ym = 0, my = 0;
    int data = 0, t1 = 0, t2 = 0;
  
    scanf("%d", &T);
  
    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &data);
  
        t1 = data / 100;
        t2 = data % 100;
  
        if ((t1 < 13) && (t1 > 0))
            my = 1;
        if ((t2 < 13) && (t2 > 0))
            ym = 1;
  
        if (my && ym)
            printf("#%d AMBIGUOUS\n", i);
        else if(my)
            printf("#%d MMYY\n", i);
        else if(ym)
            printf("#%d YYMM\n", i);
        else
            printf("#%d NA\n", i);
        my = 0;
        ym = 0;
    }
  
    return 0;
}
*/