#include <stdio.h>

int main() {
    int n, change, count = 0;
    int coins[6] = {500, 100, 50, 10, 5, 1};

    scanf("%d", &n);            // 물건값 입력
    change = 1000 - n;          // 거스름돈 계산

    for (int i = 0; i < 6; i++) {
        count += change / coins[i];  // 해당 동전 개수 더하기
        change %= coins[i];          // 남은 금액 업데이트
    }

    printf("%d\n", count);      // 최소 동전 개수 출력
    return 0;
}
