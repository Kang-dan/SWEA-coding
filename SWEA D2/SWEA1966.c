//1966.숫자를 정렬하자
/*
주어진 N 길이의 숫자열을 오름차순으로 정렬하여 출력하라.
[제약 사항]
N 은 5 이상 50 이하이다.

[입력]
가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 N 이 주어지고, 다음 줄에 N 개의 숫자가 주어진다.

[출력]
출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include <stdio.h>
int main() {
    int T, N, i, j;
    
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &N);
        int num[N];
        //숫자 입력
        for(j=0; j<N; j++){
            scanf("%d", &num[j]);
        }
        //숫자 오름차순 정렬
        int tmp = 0;
        int a = N;
        while(N>1){
        for(j=0; j<N-1; j++){
            if(num[j]>num[j+1]){
                tmp = num[j+1];
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
        N--;
        }
        //출력
        printf("#%d ", i);
        for(j=0; j<a; j++){
            printf("%d ",num[j]);
        }
        printf("\n");
    }
    return 0;
}

//Chat-GPT3.5 병합정렬(merge sort) 이용
/*
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int T, N, i, j;
    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d", &N);
        int arr[N];

        for (j = 0; j < N; j++)
            scanf("%d", &arr[j]);

        mergeSort(arr, 0, N - 1);

        printf("#%d ", i);
        for (j = 0; j < N; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }

    return 0;
}
*/