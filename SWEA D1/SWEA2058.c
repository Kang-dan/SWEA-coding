//2058.자릿수 더하기
/*
하나의 자연수를 입력 받아 각 자릿수의 합을 계산하는 프로그램을 작성하라.

[제약 사항]
자연수 N은 1부터 9999까지의 자연수이다. (1 ≤ N ≤ 9999)

[입력]
입력으로 자연수 N이 주어진다.

[출력]
각 자릿수의 합을 출력한다.
*/

#include <stdio.h>

int main() {
    int N, sum;

    scanf("%d", &N);
    if(N<1 || N>9999){
        return 1;
    }
    sum = (N%10) + ((N/10)%10) + ((N/10)/10)%10 + (((N/10)/10)/10)%10;

    printf("%d\n",sum);

    return 0;
}

// GottaDoSth님이 푼 답
/*
#include <stdio.h>
 
int main(){
     
    int n = 0;
    int sum = 0;
 
    scanf("%d", &n);
 
    if (n<1 || n>9999)
        return 1;
    else
        while (n != 0) //여기부분!!!
        {
            sum += n % 10;
            n /= 10;
        }
    printf("%d", sum);
  
    return 0;
    */

    //챗GPT가 한 코드
    /*
    #include <stdio.h>

int main() {
    int n, sum = 0;

    scanf("%d", &n);
    if (n < 1 || n > 9999) {
        printf("Invalid input\n");
        return 0;
    }
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);

    return 0;
}
/*