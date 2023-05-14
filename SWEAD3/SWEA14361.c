//14361.숫자가 같은 배수
/*
자연수 N이 있다. N의 10진법 표기(단, 0으로 시작하지 않도록 표기해야 함)에서 나타나는 숫자들을 재배열하여 N보다 큰 N의 배수(즉 2N, 3N, …, k•N, …) 를 만들 수 있는지 판단하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 자연수 N (1 ≤N ≤ 106) 이 공백 하나를 사이로 두고 주어진다.

[출력]
각 테스트 케이스마다, 주어진 자연수에 나타난 숫자들을 재배열하여 더 큰 배수를 만들 수 있다면 ‘possible’, 불가능하다면 ‘impossible’을 출력한다.
*/
#include <stdio.h>
int main(){
    int T, N, i, j, k;
    int tmp, a;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        tmp = N;
        int num[10] = {0};//0~9까지
        while(tmp>0){
            num[tmp%10]++; //flag 역할
            tmp/=10;
        }

        for(j=2; j<10; j++){
            int num_a[10] = {0};
            a = N*j;
            while(a>0){
                num_a[a%10]++;
                a/=10;
            }
            for(k=0; k<10; k++){
                if(num[k] != num_a[k]){
                    break;
                }
            }
            if(k==10){
                printf("#%d possible\n", i);
                break;
            }
        }
        if(j==10){
            printf("#%d impossible\n", i);
        }
    }
    return 0;
}

//ujajuck님 코드
/*
#include <stdio.h>
 
main(){
    int i=1,j=0,n,m,k,temp,flag=0;
    int arr[11],ans[11];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        temp=m;
        for(j=0;j<=10;j++){
            arr[j]=0;
        }
        while(temp>0){
            arr[temp%10]++;
            temp/=10;
        }
         
        for(k=2;k<10;k++){
            flag=0;
            temp=m*k;
            for(j=0;j<=10;j++) ans[j]=0; 
            while(temp>0){
                ans[temp%10]++;
                temp/=10;
            }
            for(j=0;j<=10;j++){
                if(arr[j]!=ans[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==0){
            printf("#%d possible\n",i);
        }else{
            printf("#%d impossible\n",i);
        }
    }
}
*/