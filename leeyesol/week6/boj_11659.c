#include <stdio.h>

// 입력 배열과 누적 합 배열 선언 (최대 100,000개 원소까지 처리 가능)
int arr[100001];           // 실제 입력되는 수들을 저장
long long sum[100001];     // 누적합을 저장하는 배열 (long long으로 선언하여 범위 초과 방지)

int main(void) {
    int N, M, i, j;
    long long ans;

    // N: 수의 개수, M: 구간 합을 구해야 하는 횟수
    scanf("%d %d", &N, &M);

    // 1부터 N까지 수 입력 받고 누적합 계산
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        // sum[i]: 1번부터 i번까지의 합 (sum[0]은 0으로 초기화됨)
        sum[i] = sum[i - 1] + arr[i];
    }

    // M개의 구간 합 쿼리를 처리
    while (M--) {
        scanf("%d %d", &i, &j); // i부터 j까지 구간에 대한 질의
        // 구간 합: sum[j] - sum[i - 1]을 이용하여 O(1)에 계산
        ans = sum[j] - sum[i - 1];
        printf("%lld\n", ans); // 결과 출력
    }

    return 0;
}