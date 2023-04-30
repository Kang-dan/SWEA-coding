//1984.중간 평균값 구하기
/*
10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 프로그램을 작성하라.
(소수점 첫째 자리에서 반올림한 정수를 출력한다.)

[제약 사항]
각 수는 0 이상 10000 이하의 정수이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.) */

#include <stdio.h>
int main() {
    int T, i, j;
    float num[10];
    float min, max, sum, result = 0;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        for(j=0; j<10; j++){
            scanf("%f", &num[j]);
            if(num[j]<0 || num[j]>10000) 
                printf("0이상 10000이하의 정수를 입력해주세요.\n");
        }

        min=num[0]; max=0;
        for(j=0; j<10; j++){
            if(num[j]<=min){
                min = num[j];
            }
            if(num[j]>max){
                max = num[j];
            }
        }

        sum = 0;
        for(j=0; j<10; j++){
            sum = sum + num[j];
        }
        result = (sum - (min + max)) / 8;
        printf("#%d %.f\n", i, result); //팁) %.1f는 소수점 둘째자리에서 반올림해줌.
    }
    return 0;
}

//포커님
/*
#if 01
#include <stdio.h>
 
int main(void)
{
    int tc, T;
    int input, min, max, sum;
    int i, sol;
     
    scanf("%d", &T);
    for (tc = 1; tc <= T; tc++)
    {
        sum = 0;
        min = 0x7fff0000;
        max = 0;
        for (i = 0; i < 10; i++)
        {
            scanf("%d", &input);
            sum += input;
            if (min > input)
                min = input;
            if (max < input)
                max = input;
        }
        sum = sum - min - max;
        sol = (int)(sum / 8.0 + 0.5);
        printf("#%d %d\n", tc, sol);
    }
    return 0;
}
#endif
*/