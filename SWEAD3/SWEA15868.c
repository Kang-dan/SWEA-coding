// //15868.XOR 2차원 배열 (못품)
// /*
// 0 또는 1로 구성된 두 이진 수열 a1 , a2 , ···, an 과   b1, b2, ···, bm에 대해, 이 수열의 XOR 2차원배열 Fa,b 는 n X m 크기의 배열로, Fa,b  [i][j] =ai ⊕bj   로 정의된다. 여기서 ⊕는 bitwise XOR 연산자로, 0 ⊕ 0 = 0, 0 ⊕ 1 = 1, 1 ⊕ 0 = 1, 1 ⊕ 1 = 0이다.
// 0 또는 1로 구성된 n X m 크기의 2차원 배열 T가 주어질 때, 이 배열이 어떤 이진 수열의 XOR 2차원 배열인지를 판단하는 프로그램을 작성하라.

// [입력]
// 첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
// 각 테스트 케이스의 첫 번째 줄에는 배열의 크기를 나타내는 두 자연수 n과 m (1≤n, m≤5)이 공백 하나를 사이로 두고 주어진다. 다음 n개 줄에는 길이가 m인 0 또는 1로만 구성된 문자열이 주어지는데, 이 중 i번째 줄의 j번째 글자는  T[i][j]이다.

// [출력]
// 각 테스트 케이스마다, T가 어떤 이진 수열의 XOR 2차원 배열이라면 (즉, 어떤 이진 수열 a1 , a2 , ···, an과   b1, b2, ···, bm에 대해 T=Fa,b  라면) ‘yes’를, 그렇지 않다면 ‘no’를 출력한다.
// */

// #include <stdio.h>
// int main(){
//     int T, i, j, k;
//     int n, m;

//     scanf("%d", &T);
//     for(i=1; i<=T; i++){
//         scanf("%d %d",&n, &m);
//         //0또는 1 입력
//         char NM[n+1][m+1];
//         for(j=0; j<n; j++){
//             scanf("%s", &NM[j][0]); // scanf("%s", NM[j]); 로도 가능함.
//         }
//         //XOR맞는지 확인
//         if(n>=m){
//             for(j=0; j<m; j++){
//                 for(k=0; k<m; k++){
//                     if(NM[j][k] != NM[k][j]){
//                         printf("#%d no\n", i);
//                         break;
//                     }
//                 }
//                 if(k<m) break;
//             }
//             if(k==m && j==m) printf("#%d yes\n", i); 
//         }
//         else if(n<m){
//             for(j=0; j<n; j++){
//                 for(k=0; k<n; k++){
//                     if(NM[j][k] != NM[k][j]){
//                         printf("#%d no\n", i);
//                         break;
//                     }
//                 }
//                 if(k<n) break;
//             }
//             if(k==n && j==n) printf("#%d yes\n", i); 
//         } 
//     }
//     return 0;
// }

//달패님 코드
#include<stdio.h>
 
char f[7][7];
int n, m;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    char tmp;
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int is_xor_matrix = 1;
 
        scanf("%d %d ", &n, &m);
 
        printf("#%d ", test_case);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &f[i][j]);
            }
            scanf("%c", &tmp);
        }
        for (int i = 1; i < n; i++) {
            int is_same = (f[i][0] == f[0][0]);
            for (int j = 1; j < m; j++) {
                if (is_same != (f[i][j] == f[0][j])) {
                    is_xor_matrix = 0;
                    break;
                }
            }
            if (!is_xor_matrix)
                break;
        }
        if (!is_xor_matrix) {
            printf("no\n");
            continue;
        }
 
        for (int j = 1; j < m; j++) {
            int is_same = (f[0][0] == f[0][j]);
            for (int i = 1; i < n; i++) {
                if (is_same != (f[i][0] == f[i][j])) {
                    is_xor_matrix = 0;
                    break;
                }
            }
            if (!is_xor_matrix)
                break;
        }
        if (!is_xor_matrix) {
            printf("no\n");
            continue;
        }
        printf("yes\n");
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
