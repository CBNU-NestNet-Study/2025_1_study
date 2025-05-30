#include <stdio.h>   // 표준 입출력 함수 사용
#include <stdlib.h>  // malloc, free 등 동적 메모리 함수 사용

int main() {
    int N, K;

    // N: 총 원소 개수, K: 부분합을 구할 연속된 원소 개수
    scanf("%d %d", &N, &K);

    // 정수형 배열 arr를 동적으로 할당 (크기 N)
    int* arr = malloc(N * sizeof(int));

    // 배열 원소 입력
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 첫 번째 슬라이딩 윈도우 합 계산 (0 ~ K-1 인덱스까지)
    int window_sum = 0;
    for (int i = 0; i < K; i++) {
        window_sum += arr[i];
    }

    // max_sum: 현재까지 발견한 최대 부분합 초기화
    int max_sum = window_sum;

    // 슬라이딩 윈도우 기법 사용하여 부분합 갱신
    // i는 윈도우의 시작 위치 (1 ~ N-K)
    for (int i = 1; i <= N - K; i++) {
        // 앞의 값을 하나 빼고, 뒤의 새 값을 하나 더함
        window_sum = window_sum - arr[i - 1] + arr[i + K - 1];

        // 현재 윈도우의 합이 지금까지 최대값보다 크면 갱신
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    // 최댓값 출력
    printf("%d\n", max_sum);

    // 동적으로 할당한 메모리 해제
    free(arr);

    return 0;
}