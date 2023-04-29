//2025.N줄 덧셈
/*
1부터 주어진 숫자만큼 모두 더한 값을 출력하시오.
단, 주어질 숫자는 10000을 넘지 않는다.

[예제]
주어진 숫자가 10 일 경우 출력해야 할 정답은,
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
*/

#include <stdio.h>
int main(void){
    int i, num, sum = 0;

    scanf("%d", &num);
    if(num > 10000){
        printf("10000이하의 숫자를 입력해주세요.\n");
        return 1;
    }
    for(i=1; i<=num; i++){
    sum += i;
    }
    printf("%d\n", sum);

    return 0;
}