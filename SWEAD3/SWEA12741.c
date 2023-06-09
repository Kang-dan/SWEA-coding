//12741.두 전구
/*
두 개의 전구 X와 Y가 있다. 당신은 0초에서부터 시작하여 100초간 두 전구가 언제 켜지는지를 관찰하였다.
  관찰 결과, 전구 X는 관찰 시작 경과 후 A초에서부터 관찰 시작 경과 후 B초까지에만 켜져 있었다. 전구 Y는 관찰 시작 경과 후 C초에서부터 관찰 시작 경과 후 D초까지에만 켜져 있었다.
  당신이 두 전구를 관찰하던 100초 중 두 전구가 동시에 켜져 있던 시간은 몇 초일까?

[입력]
  첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
  각 테스트 케이스의 첫 번째 줄에는 네 개의 정수 A, B, C, D (0 ≤ A < B ≤ 100, 0 ≤ C < D ≤ 100)가 공백 하나를 사이로 두고 순서대로 주어진다.

[출력]
  각 테스트 케이스마다, 두 전구가 동시에 켜져 있던 시간이 몇 초인지를 한 줄에 하나씩 출력한다.
*/

//CHAT-gpt3.5 (효율적)
#include <stdio.h>

int main(void) {
    int T, a, b, c, d;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int a_c = (a >= c) ? a : c; //이 부분 효율적
        int b_d = (b >= d) ? d : b;
        
        int diff = b_d - a_c;
        if (diff > 0)
            printf("#%d %d\n", i, diff);
        else
            printf("#%d 0\n", i);
    }
    
    return 0;
}

//내 코드
/*
#include <stdio.h>
int main(void){
    int T, N, a,b,c,d, i, j;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int a_c = 0, b_d = 0;
        //a,c중 더 큰걸로
        if(a>=c){
            a_c = a;
            //b,d중 더 작은 걸로
            if(b>=d){
                b_d = d;
            }
            else{
                b_d = b;
            }
        }
        else{
            a_c = c;
            //b,d중 더 작은 걸로
            if(b>=d){
                b_d = d;
            }
            else{
                b_d = b;
            }
        }
        if(b_d - a_c > 0) printf("#%d %d\n", i, b_d-a_c);
        else printf("#%d 0\n", i);
    }
    return 0;
}
*/