//9280. 진용이네 주차타워
/*
부지런한 진용이는 정문 앞에서 유료 주차장 운영하고 있다. 이 주차장은 1 부터 n 까지 번호가 매겨진 n 개의 주차 공간을 가지고 있다.
매일 아침 모든 주차 공간이 비어 있는 상태에서 영업을 시작하며, 다음과 같은 방식으로 운영된다.

차가 주차장에 도착하면, 진용이는 비어있는 주차 공간이 있는지 검사한다.
비어있는 공간이 없다면, 빈 공간이 생길 때까지 차량을 입구에서 기다리게 한다.
빈 주차 공간이 있으면 진용이는 곧바로 주차를 시키며, 주차 가능한 공간 중 번호가 가장 작은 주차 공간에 주차하도록 한다.
만약 주차를 기다리는 차량이 여러 대라면, 입구의 대기장소에서 자기 차례를 기다려야 한다. 운전자들은 예의가 바르기 때문에 새치기를 하지 않는다.

주차요금은 차량의 무게와 주차 공간마다 따로 책정된 단위 무게당 금액을 곱한 가격이다. 진용이네 주차장에서는 종일 이용권만을 판매하기 때문에 이용시간은 고려하지 않는다.
 
진용이는 오늘 주차장을 이용할 m 대의 차량들이 들어오고 나가는 순서를 알고 있다.
진용이의 주차장이 오늘 하루 벌어들일 총 수입을 계산하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC 가 주어진다.
이후 TC 개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되어 있다.

첫 번째 줄에 자연수  n 과  m 이 주어진다. (1 ≤ n  ≤ 100, 1 ≤ m  ≤ 2000)
n 개의 줄에 i 번째 주차 공간의 단위 무게당 요금 Ri 가 정수로 주어진다. (1 ≤ Ri  ≤ 100)
m 개의 줄에 차량 i 의 무게 Wi 가 정수로 주어진다. 차량번호 i 와 차량의 도착 순서는 아무런 관계가 없다. (1 ≤ Wi  ≤ 10000)
이후  2m 개의 줄에 차량들의 주차장 출입 순서가 하나의 정수  x 로 주어진다.
주어진 정수 x 가 양수면, x 번 차가 주차장에 들어옴을 뜻한다.
x 가 음수면, -x 번 차가 주차장을 나감을 뜻한다.

주차장에 들어오지 않은 차량이 주차장에서 나가는 경우는 주어지지 않는다.
1 번부터 m 번까지 모든 차량은 정확하게 한 번씩 주차장에 들어오고, 한 번씩 주차장에서 나간다.
또한 입구에서 대기 중인 차량이 주차를 하지 못하고 그냥 돌아가는 경우는 없다.

[출력]
각 테스트 케이스마다 ‘#t ’(t 는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 진용이가 오늘 하룻동안 벌어들일 수입을 출력하라.
*/

#include <stdio.h>
int main(void){
    int T, i, j, k;
    int n, m;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d", &n, &m);
        int r[n+1], w[m+1], x[2*m+1];
        for(j=1; j<n+1; j++){
            scanf("%d", &r[j]);
        }
        for(j=1; j<m+1; j++){
            scanf("%d", &w[j]);
        }
        for(j=1; j<2*m+1; j++){
            scanf("%d", &x[j]);
        }

        int flag[101] = {0}; //주차공간 여부 (실사용 인덱스는 0부터 n-1까지)
        int sum = 0; //수입
        int flag_index[101]={0}; //들어온 x[j]값 저장
        int row[200001] = {0}; //들어오는 차량 대기
        int z;
        for(j=1; j<2*m+1; j++){
            if(x[j]>0){
                for(k=1; k<n+1; k++){
                    if(flag[k]==0){
                        flag[k]++;
                        flag_index[k] = x[j]; //들어가는 차의 주차한 무게인덱스저장
                        break;
                    }
                }
                if(k==n+1) row[j]=x[j];
            }
            else if(x[j]<0){
                for(k=1; k<n+1; k++){
                    if(flag_index[k]==-1*x[j]){
                        flag[k]--;
                        sum = sum + r[k]*w[-1*x[j]];
                        //대기하고 있는 차량 하나씩 넣어주기
                        for(z=1; z<2*m+1; z++){
                            if(row[z]!=0){
                                flag_index[k] = row[z];
                                row[z] = 0;
                                flag[k]++;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        printf("#%d %d\n", i, sum);
    }
    return 0;
}