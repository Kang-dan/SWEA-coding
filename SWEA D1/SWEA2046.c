//2046.스탬프 찍기
/*
주어진 숫자만큼 # 을 출력해보세요.
주어질 숫자는 100,000 이하다.
*/

#include <stdio.h>

int main(){
    int num, i;

    scanf("%d", &num);
    if(num > 100000){
        printf("100000이하의 숫자로 입력해주세요.\n");
        return 0;
    }
    for(i=0; i<num; i++){
        printf("#");
    }
    printf("\n");

    return 0;
}