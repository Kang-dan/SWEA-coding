//2019.더블더블
/*
1부터 주어진 횟수까지 2를 곱한 값(들)을 출력하시오.
주어질 숫자는 30을 넘지 않는다.
*/

#include <stdio.h>

int main(void){
    int num, i, result = 1;

    scanf("%d", &num);
    if(num>30){
        printf("30 이하의 숫자를 입력해주세요.\n");
        return 1;
    }
    else {
        printf("1 ");
        for(i=1; i<=num; i++){
            result = result * 2;
            printf("%d ", result);
        }
        printf("\n");
    }
    return 0;
}

//조영주님 코드
/*
#include <stdio.h>
 
int main(void)
{
    int num, i, sol = 1;
     
    scanf("%d", &num);
     
    for(i=0 ; i<num+1 ; i++)
    {
        printf("%d ", sol);
        sol *= 2;
    }
     
    return 0;
}
*/