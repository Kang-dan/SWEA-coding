//1288.새로운 불면증 치료법
/*
호석이는 불면증에 걸렸다. 그래서 잠이 안 올 때의 민간요법 중 하나인 양 세기를 하려고 한다.
호석이는 1번 양부터 순서대로 세는 것이 재미없을 것 같아서 N의 배수 번호인 양을 세기로 하였다.
즉, 첫 번째에는 N번 양을 세고, 두 번째에는 2N번 양, … , k번째에는 kN번 양을 센다.
이렇게 숫자를 세던 호석이에게 잠은 더 오지 않고 다음과 같은 궁금증이 생겼다.
이전에 셌던 번호들의 각 자리수에서 0에서 9까지의 모든 숫자를 보는 것은 최소 몇 번 양을 센 시점일까?

예를 들어 N = 1295이라고 하자.
첫 번째로 N = 1295번 양을 센다. 현재 본 숫자는 1, 2, 5, 9이다.
두 번째로 2N = 2590번 양을 센다. 현재 본 숫자는 0, 2, 5, 9이다.
현재까지 본 숫자는 0, 1, 2, 5, 9이다.
세 번째로 3N = 3885번 양을 센다. 현재 본 숫자는 3, 5, 8이다.
현재까지 본 숫자는 0, 1, 2, 3, 5, 8, 9이다.
네 번째로 4N = 5180번 양을 센다. 현재 본 숫자는 0, 1, 5, 8이다.
현재까지 본 숫자는 0, 1, 2, 3, 5, 8, 9이다.
다섯 번째로 5N = 6475번 양을 센다. 현재 본 숫자는 4, 5, 6, 7이다.
현재까지 본 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9이다.
5N번 양을 세면 0에서 9까지 모든 숫자를 보게 되므로 호석이는 양 세기를 멈춘다.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 N (1 ≤ N ≤ 106)이 주어진다.

[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
최소 몇 번 양을 세었을 때 이전에 봤던 숫자들의 자릿수에서 0에서 9까지의 모든 숫자를 보게 되는지 출력한다.
( 호석이는 xN번 양을 세고 있다. )

(입력예시)
5
1
2
11
1295
1692
(출력예시)
#1 10
#2 90
#3 110
#4 6475
#5 5076
*/

#include <stdio.h>
int main(){
    int X, N, i;

    scanf("%d", &X);
    for(i=1; i<=X; i++){
        int num[10] = {0}; //0~9
        scanf("%d", &N); //배수
        int b = 0; //0~9까지 다 세면 10
        int c;
        int j=1;
        while(b<10){
            c=N*j;
            j++;
            while(c>0){
                if(num[c%10] == 0){
                    num[c%10] = 1;
                    b++;
                }
                c=c/10;
            }
        }
        printf("#%d %d\n", i, N*(j-1));
    }
    return 0;
}

//Chat-GPT3.5
/*
#include <stdio.h>
#include <stdbool.h>

bool check_digits(bool digits[]) {
    // digits 배열이 모두 true 인지 확인하는 함수
    for (int i = 0; i < 10; i++) {
        if (!digits[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int count = 0;
        bool digits[10] = {false}; // 0~9까지의 숫자가 등장했는지 여부를 저장하는 배열
        while (!check_digits(digits)) {
            count++;
            int number = count * N; // N의 배수인 양의 번호
            while (number > 0) { // 각 자리 숫자를 확인하면서 digits 배열을 업데이트
                digits[number % 10] = true;
                number /= 10;
            }
        }
        printf("#%d %d\n", t, count * N);
    }
    return 0;
}
*/