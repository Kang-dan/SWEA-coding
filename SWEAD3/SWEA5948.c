/* 5948. 새샘이의 7-3-5 게임
숫자게임을 좋아하는 새샘이는 서로 다른 7개의 정수 중에서 3개의 정수를 골라 합을 구해서 수를 만들려고 한다.
이렇게 만들 수 있는 수 중에서 5번째로 큰 수를 출력하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 7개의 서로 다른 정수가 공백으로 구분되어 주어진다. 각 정수는 1이상 100이하이다.

[출력]
각 테스트 케이스마다 첫 번째 줄에는 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 답을 출력한다.
*/

#include <stdio.h>
int main(){
    int T, i, j, k, z, a;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        int num[8] = {0};
        for(j=0; j<7; j++){
            scanf("%d", &num[j]);
        }
        int result[36];
        a = 0;
        for(j=0; j<5; j++){
            for(k=j+1; k<6; k++){
                for(z=k+1; z<7; z++){
                    result[a] = num[j] + num[k] + num[z];
                    a++;
                }
            }
        }
        int flag[36] = {0}, max = 0, remember_index = 0, count = 0;
        int remember_max = 0;
        while(1){
            max = 0;
            for(j=0; j<a; j++){
                if(count == 0 && max < result[j]){
                    max = result[j];
                    remember_index = j;
                }
                else if(count != 0 && max<result[j] && result[j] < remember_max){
                    max = result[j];
                    remember_index = j;
                }
            }
            remember_max = max;
            flag[remember_index] = 1;
            count++;
            if(count==5){
                printf("#%d %d\n", i, remember_max);
                break;
            }
        }
    }
    return 0;
}