//1974.스도쿠 검증
/*
스도쿠는 숫자퍼즐로, 가로 9칸 세로 9칸으로 이루어져 있는 표에 1 부터 9 까지의 숫자를 채워넣는 퍼즐이다.
같은 줄에 1 에서 9 까지의 숫자를 한번씩만 넣고, 3 x 3 크기의 작은 격자 또한, 1 에서 9 까지의 숫자가 겹치지 않아야 한다.
입력으로 9 X 9 크기의 스도쿠 퍼즐의 숫자들이 주어졌을 때, 위와 같이 겹치는 숫자가 없을 경우, 1을 정답으로 출력하고 그렇지 않을 경우 0 을 출력한다.

[제약 사항]
1. 퍼즐은 모두 숫자로 채워진 상태로 주어진다.
2. 입력으로 주어지는 퍼즐의 모든 숫자는 1 이상 9 이하의 정수이다.

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.
테스트 케이스는 9 x 9 크기의 퍼즐의 데이터이다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.) */

//Chat-GPT3.5
#include <stdio.h>

int check_row(int puzzle[9][9], int row) { // 같은 행 검증
    int count[10] = {0};
    for (int col = 0; col < 9; col++) {
        int num = puzzle[row][col];
        count[num]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (count[i] != 1) {
            return 0; // 같은 숫자가 두 번 이상 나온 경우
        }
    }
    return 1; // 모든 숫자가 한 번씩만 나온 경우
}

int check_col(int puzzle[9][9], int col) { // 같은 열 검증
    int count[10] = {0};
    for (int row = 0; row < 9; row++) {
        int num = puzzle[row][col];
        count[num]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (count[i] != 1) {
            return 0; // 같은 숫자가 두 번 이상 나온 경우
        }
    }
    return 1; // 모든 숫자가 한 번씩만 나온 경우
}

int check_box(int puzzle[9][9], int row_start, int col_start) { // 같은 3x3 박스 검증
    int count[10] = {0};
    for (int row = row_start; row < row_start + 3; row++) {
        for (int col = col_start; col < col_start + 3; col++) {
            int num = puzzle[row][col];
            count[num]++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (count[i] != 1) {
            return 0; // 같은 숫자가 두 번 이상 나온 경우
        }
    }
    return 1; // 모든 숫자가 한 번씩만 나온 경우
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int puzzle[9][9];
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                scanf("%d", &puzzle[row][col]);
            }
        }
        int valid = 1;
        for (int i = 0; i < 9; i++) {
            valid = valid && check_row(puzzle, i); // 모든 행 검증
            valid = valid && check_col(puzzle, i); // 모든 열 검증
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                valid = valid && check_box(puzzle, row, col); // 모든 3x3 박스 검증
            }
        }
        printf("#%d %d\n", t, valid);
    }
    return 0;
}

//내가 한 코드 (모두 5가 들어갈 경우 안됨)
/*
#include <stdio.h>

int main() {
    int T, i, j, k;
    int s[10][10];
    int sum = 0;
    int check;

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        check = 0;
        //스도쿠 채우기
        for(j=0; j<9; j++){
            for(k=0; k<9; k++){
                scanf("%d", &s[j][k]);
            }
        }
        //가로줄 검사
        for(j=0; j<9; j++){
            sum = 0;
            for(k=0; k<9; k++){
                sum = sum + s[j][k];
            }
            if(sum != 45){
                printf("#%d 0\n", i);
                check++;
                break;
            }
        }
        //세로줄 검사
        for(j=0; j<9; j++){
            sum = 0;
            for(k=0; k<9; k++){
                sum = sum + s[k][j];
            }
            if(sum != 45){
                printf("#%d 0\n", i);
                check++;
                break;
            }
        }
        //3x3 검사
        int a = 0;
        while(a<9){
        sum = 0;
        for(j=a; j<a+3; j++){
            for(k=a; k<a+3; k++){
                sum = sum + s[j][k];
            }
        }
        if(sum != 45){
            printf("#%d 0\n", i);
            check++;
            break;
        }
        a+=3;
        }
        if(check == 0) printf("#%d 1\n", i);
    }
    return 0;
}
/*

/* 장모기님 코드
#include <stdio.h>
 
int T;
int arr[10][10];
 
int main()
{
    scanf("%d",&T);
    for (int testcase = 1; testcase <= T; testcase++)
    {
        int flag = 0;
        for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) scanf("%d", &arr[i][j]);
 
        for (int i = 1; i <= 9; i++)
        {
            bool check_v[10] = { 0, };
            bool check_p[10] = { 0, };
            for (int j = 1; j <= 9; j++)
            {
                if (check_p[arr[i][j]])
                {
                    flag = 1;
                    break;
                }
                else check_p[arr[i][j]] = 1;
                if (check_v[arr[j][i]])
                {
                    flag = 1;
                    break;
                }
                else check_v[arr[j][i]] = 1;
            }
            if (flag == 1) break;
        }
        if(flag == 0)
        {
            int x = 1, y = 1;
            while (1)
            {
                bool check[10] = { 0, };
                for (int i = y; i <= y + 2; i++)
                {
                    for (int j = x; j <= x + 2; j++)
                    {
                        if (check[arr[i][j]])
                        {
                            flag = 1;
                            break;
                        }
                        else check[arr[i][j]] = 1;
                    }
                    if (flag == 1) break;
                }
                if (flag == 1) break;
                else
                {
                    x += 3;
                    if (x == 10)
                    {
                        x = 1;
                        y += 3;
                    }
                    if (y == 10) break;
                }
            }
        }
        if (flag == 1) printf("#%d 0\n", testcase);
        else printf("#%d 1\n", testcase);
         
    }
}
*/