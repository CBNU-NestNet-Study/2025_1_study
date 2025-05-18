#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);          // 계단 수 입력

    int stair[301];
    for (int i = 1; i <= n; i++)
        scanf("%d", &stair[i]);  // 계단 점수 입력

    int dp[301] = {0};
    if (n >= 1) dp[1] = stair[1];
    if (n >= 2) dp[2] = stair[1] + stair[2];
    if (n >= 3) dp[3] = (stair[1] + stair[3] > stair[2] + stair[3] ? stair[1] + stair[3] : stair[2] + stair[3]);

    for (int i = 4; i <= n; i++) {
        int useTwoStep = dp[i-2] + stair[i];                 // 한 칸 뛰어오고
        int useOnePlusSkip = dp[i-3] + stair[i-1] + stair[i]; // 두 칸 뛰고 한 칸
        dp[i] = (useTwoStep > useOnePlusSkip ? useTwoStep : useOnePlusSkip);
    }

    printf("%d\n", dp[n]);      // 최대 점수 출력
    return 0;
}
