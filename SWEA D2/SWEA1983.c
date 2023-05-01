// //1983.조교의 성적 매기기
// /*
// 학기가 끝나고, 학생들의 점수로 학점을 계산중이다.
// 학점은 상대평가로 주어지는데, 총 10개의 평점이 있다.
// A+ A0 A- B+ B0 B- C+ C0 C- D0

// 학점은 학생들이 응시한 중간/기말고사 점수 결과 및 과제 점수가 반영한다.
// 각각 아래 비율로 반영된다.
// 총점 = 중간고사(35%) + 기말고사(45%) + 과제(20%)

// 10 개의 평점을 총점이 높은 순서대로 부여하는데,
// 각각의 평점은 같은 비율로 부여할 수 있다.
// 예를 들어, N 명의 학생이 있을 경우 N/10 명의 학생들에게 동일한 평점을 부여할 수 있다.

// 입력으로 각각의 학생들의 중간, 기말, 과제 점수가 주어지고,
// 학점을 알고싶은 K 번째 학생의 번호가 주어졌을 때,
// K 번째 학생의 학점을 출력하는 프로그램을 작성하라.

// [제약사항]
// 1. N은 항상 10의 배수이며, 10이상 100이하의 정수이다. (10 ≤ N ≤ 100)
// 2. K는 1 이상 N 이하의 정수이다. (1 ≤ K ≤ N)
// 3. K 번째 학생의 총점과 다른 학생의 총점이 동일한 경우는 입력으로 주어지지 않는다.

// [입력]
// 입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
// 다음 줄부터 각 테스트 케이스가 주어진다.
// 테스트 케이스의 첫 번째 줄은 학생수 N 과, 학점을 알고싶은 학생의 번호 K 가 주어진다.
// 테스트 케이스 두 번째 줄 부터 각각의 학생이 받은 시험 및 과제 점수가 주어진다.

// [출력]
// 테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
// (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.) */

#include <stdio.h>
#include <string.h>

int main(){
    int T, N, K; //테스트케이스, 학생수, K번째 학생
    float m, f, p; //총점, 중간35%, 기말45%, 과제20%
    int i, j, k;
    char abcd[10][3] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &N, &K);
        if(N%10!=0 || N>100){
            printf("10이상 100이하의 정수를 입력해주세요.\n");
            return 1;
        }
        //점수 입력
        float result[100]; // 총점
        float K_result = 0;
        for(j=0; j<N; j++){
            scanf("%f %f %f", &m,&f,&p); //중간, 기말, 과제
            result[j] = m*0.35 + f*0.45 + p*0.20; // 총점
            if(j+1 == K){ // K번째 총점 기억하기
                K_result = result[j];
            }
        }
        //총점 큰수<->작은수로 정렬
        float tmp = 0;
        int k = N-1;
        while(k>=1){
            for(j=1; j<=k; j++){
                if(result[j-1] < result[j]){
                    tmp = result[j];
                    result[j] = result[j-1];
                    result[j-1] = tmp;
                }
            }
            k--;
        }
        //abcd[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
        //N/10명씩 같은 평점
        int pivot = 0;
        for(j=0; j<N; j+=N/10){
            for(k=j; k<j+N/10; k++){ //k번째 학생 총점이랑 같으면
                if(result[k] == K_result){
                    printf("#%d %s\n", i, abcd[pivot]);
                    break;
                }
            }
            pivot++;
        }
    }
    return 0;
}

//퍄퍄퍄퍄님 코드
/*
#include <stdio.h>
 
int main()
{
    int tc;
    scanf("%d", &tc);
    char grade[10][3] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
    for (int t = 1; t <= tc; t++)
    {
 
        double sum[100];
        int n, k;
        int mid, fin, repo,res;
        scanf("%d %d", &n, &k);
        for (int i = 0; i<n; i++)
        {
            scanf("%d %d %d", &mid, &fin, &repo);
            sum[i] = mid * 0.35 + fin * 0.45 + repo * 0.2;
        }
        res = 0;
        for (int i = 0; i<n; i++)
        {
            if (sum[i] > sum[k - 1])
                res++;
        }
        printf("#%d %s\n", t, grade[res / (n / 10)]);
    }
    return 0;
}
*/