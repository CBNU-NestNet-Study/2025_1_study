#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // N: 전체 일수, K: 연속일 수

    int *arr = (int *)malloc(sizeof(int) * (N + 1)); // 온도 배열

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]); // 각 날의 온도 입력
    }

    // 처음 K일의 합 구하기
    int sum = 0;
    for (int i = 1; i <= K; i++) {
        sum += arr[i];
    }
    int max_sum = sum; // 최대 합 초기값 설정d

    // 슬라이딩 윈도우: 다음 날 들어오고 이전 날 빠지기
    for (int i = K + 1; i <= N; i++) {
        sum += arr[i];       // 신규 날 더하기
        sum -= arr[i - K];   // 마지막 K일 전 날 빼기
        if (sum > max_sum) {
            max_sum = sum;   // 더 큰 합이면 갱신
        }
    }

    printf("%d\n", max_sum); // 결과 출f

    free(arr);
    return 0;
}
