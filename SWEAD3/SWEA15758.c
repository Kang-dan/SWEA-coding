// //15758.무한 문자열
// /*
// 문자열 S에 대해, f(S)를 S를 무한히 반복해서 얻은 문자열이라고 정의하자. 예를 들어 f(“abcd”) = “abcdabcdabcdabcd…” 이다.
// S≠T이라도 f(S)=f(T) 일 수 있다. 예를 들어 S = “ababab”, T = “abab”라면 f(S)와 f(T) 모두 “ababababababab…”이다.
// 두 개의 문자열 S와 T가 주어질 때, f(S)=f(T)인지의 여부를 구하는 프로그램을 작성하라.

// [입력]
// 첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
// 각 테스트 케이스는 한 개의 줄로 이루어지며, 각 줄에는 두 개의 문자열 S와 T가 공백 하나를 사이로 두고 주어진다. S와 T는 알파벳 소문자(a-z)로만 구성되어 있으며, 1글자 이상 50글자 이하이다.

// [출력]
// 각 테스트 케이스마다, f(S)=f(T)라면 ‘yes’를, f(S)≠f(T)라면 ‘no’를 출력한다.
// */

// #include <stdio.h>
// #include <string.h>

// int main(){
//     int T, i, j, k;
//     char F[51], S[51];

//     scanf("%d", &T);
//     for(i=1; i<=T; i++){
//         scanf("%s %s", F, S);
//         //두 문자열 맞는지 비교 (F>S)
//         j=0;
//         if(strlen(F) > strlen(S)){
//             while(j<strlen(S)){
//                 if(F[j]!=S[j]){
//                     printf("#%d no\n", i);
//                     break;
//                 }
//                 j++;
//             }
//             //두 문자열 비교하고, 더 긴 문자열의 남은 곳도 반복되는지 확인
//             if(j==strlen(S)){
//                 k= 0;
//                 while(j<strlen(F)){
//                     if(F[j]!=S[k]){
//                         printf("#%d no\n", i);
//                         break;
//                     }
//                     k++; j++;
//                     if(k == strlen(S)){
//                         k = 0;
//                     }
//                 }
//                 if(j==strlen(F)) printf("#%d yes\n", i);
//             }
//         }
//         //두 문자열 맞는지 비교 (F<=S)
//         else if(strlen(F) <= strlen(S)) {
//             while(j<strlen(F)){
//                 if(F[j]!=S[j]){
//                     printf("#%d no\n", i);
//                     break;
//                 }
//                 j++;
//             }
//             //두 문자열 비교하고, 더 긴 문자열의 남은 곳도 반복되는지 확인
//             if(j>=strlen(F)){
//                 k=0;
//                 while(j<strlen(S)){
//                     if(S[j]!=F[k]){
//                         printf("#%d no\n", i);
//                         break;
//                     }
//                     k++; j++;
//                     if(k == strlen(F)){
//                         k = 0;
//                     }
//                 }
//                 if(j>=strlen(S)) printf("#%d yes\n", i);
//             }
//         }
//     }
//     return 0;
// }

#include <stdio.h>
int main(){
    int T,i, j, k;
    char F[51]; S[51];

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%s %s", F, S);
        j=1;
        char a[51];
        while(j<strlen(F)){
            if(F[0]== F[j]){
                k=0;
                while(k<j-1){
                    if(F[k]!=F[j]) break;
                }
                if(k==j-1){
                    
                }
            }
            j++;
        }
    }
    return 0;
}