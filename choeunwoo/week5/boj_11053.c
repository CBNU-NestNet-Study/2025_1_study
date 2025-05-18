#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);            // 수열 길이 입력

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);   // 수열 요소 입력

    int dp[1000];
    int max_len = 1;

    // dp[i]: arr[i]를 마지막으로 하는 증가 부분 수열의 최대 길이
    for (int i = 0; i < n; i++) {
        dp[i] = 1;              // 자기 자신만 있을 때 길이 1
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_len)
            max_len = dp[i];    // 전체 최대 길이 갱신
    }

    printf("%d\n", max_len);   // 정답 출력
    return 0;
}
