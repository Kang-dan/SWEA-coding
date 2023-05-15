//13732.정사각형 판정
/*
N×N 크기의 격자판이 있다. 각각의 격자는 비어 있거나(‘.’), 막혀 있다(‘#’). 이때, 막혀 있는 칸들이 하나의 정사각형을 이루는지를 판단하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 격자판의 크기 N (1≤N≤20 이 주어진다. 다음 N개의 줄은 격자판의 배치를 나타내며, 각 줄에는 ‘.’ 또는 ‘#’로만 이루어진 길이가 N인 문자열이 주어진다. 모든 격자판에는 최소 1개 이상의 ‘#’ 칸이 있음이 보장된다.

[출력]
각 테스트 케이스마다 격자판의 막혀 있는 칸들이 하나의 정사각형을 이루면 ‘yes’를, 그렇지 않다면 ‘no’를 출력한다.
*/

#include <stdio.h>
int main(void){
    int T, N, i, j, k;
    char pan[20][20];
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        //판 입력
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                scanf(" %c", &pan[j][k]);
            }
        }
        //정사각형 검사
        int a=0; //가로줄 길이
        int flag_k=0, flag_j=-1;//가로 세로#시작부분 인덱스
        for(j=0; j<N; j++){
            for(k=0; k<N; k++){
                //..##.# 이런 경우
                if(pan[flag_j][k]=='#' && a>0){
                    printf("#%d no\n", i);
                    break;
                }
                else if(pan[j][k]=='#' && a==0){
                    flag_j = j;//세로
                    flag_k = k;//가로
                    a=1; //한변 길이
                    while(k<N){
                        k++;
                        if(pan[j][k]!='#') break;
                        a++;
                    }
                }
            }
            if(k<N) break;
            if(flag_j != -1) break;
        }
        //다음 가로줄부터검사 시작
        if(flag_j != -1 && k>=N){
            for(j=flag_j+1; j<N; j++){
                for(k=0; k<N; k++){
                    if(j>=flag_j+a && pan[j][k] == '#'){
                        printf("#%d no\n", i);
                        break;
                    }
                    else if(j<flag_j+a && k>=flag_k && k<flag_k+a && pan[j][k] != '#'){
                        printf("#%d no\n", i);
                        break;
                    }
                    else if(j<flag_j+a && (k<flag_k || k>=flag_k+a) && pan[j][k] == '#'){
                        printf("#%d no\n", i);
                        break;
                    }
                }
                if(k<N) break;
            }
            if(j==N) printf("#%d yes\n", i);
        }
    }
    return 0;
}