//13038.교환학생
/*
세계 최고의 명문 대학교 삼성대학교에는 수많은 교환학생들이 존재한다. 삼성대학교는 연중무휴로 운영되지만, 교환학생들을 위한 수업은 특정 요일에만 진행된다. 이 정보는 7개의 정수 a1, a2, …, a7으로 표현되는데 (ai = 0 or ai = 1):

  · 일요일에 교환학생을 위한 수업이 열리면 a1 = 1, 아니면 0
  · 월요일에 교환학생을 위한 수업이 열리면 a2 = 1, 아니면 0
  · …
  · 토요일에 교환학생을 위한 수업이 열리면 a7 = 1, 아니면 0
 
  수업이 어떠한 요일에도 열리지 않는 경우는 없다고 가정해도 된다.
  당신은 삼성대학교에서 교환학생으로 n일 동안 수업을 들으려고 한다. 목표를 이루기 위해 삼성대학교에 지내야 하는 최소 일수를 출력하라.

[입력]
  첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.

  · 첫 번째 줄에 정수 n이 주어진다. (1≤ n ≤105)
  · 이후 7개의 정수 a1, a2, …, a7이 주어진다. (0 ≤ ai ≤ 1)

[출력]
  각 테스트 케이스마다 문제의 정답을 출력하라.
*/

#include <stdio.h>
int main(void){
    int T, N, i, j, k, day, tmp, b;
    int a[8];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        for(j=0; j<7; j++){
            scanf("%d", &a[j]);
        }
        day = 0;
        k=0; tmp = 0;
        while(1){
            b = 0;
            int c = 0;
            for(j=0; j<7; j++){
                if(a[j] == 1) {
                    c++;
                    if(c == 1) b = j;
                    day++;
                }
                if(day == N) {
                    b = j-b+1;
                    break;
                }
            }
            if(day == N) break;
            else if(day != N){
            day = 0;
            b = 0;
            for(j=0; j<7; j++){
                if(a[j] == 1){
                    b = 7-j;
                    break;
                }
            }
            if(day == N) break;
            if(k==7) {
                k=0; //순환
                tmp++;
            }
            if(a[k] == 1) day++;
            k++;
            }
        }
        printf("#%d %d\n", i, tmp*7+k+b);
    }
    return 0;
}