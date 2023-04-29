//2027.대각선 출력하기
/*
주어진 텍스트를 그대로 출력하세요.
#++++
+#+++
++#++
+++#+
++++#
*/

/*
#include <stdio.h>

int main() {
    printf("#++++\n");
    printf("+#+++\n");
    printf("++#++\n");
    printf("+++#+\n");
    printf("++++#\n");
    return 0;
}
*/

#include <stdio.h>
int main() {
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(i==j){
                printf("#");
            }
            else
                printf("+");
        }
        printf("\n");
    }
    return 0;
}