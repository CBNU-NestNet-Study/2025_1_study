#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);      // n 입력

    // 동적 프로그래밍으로 fib(n) 계산
    int f[41];            // n ≤ 40
    f[1] = f[2] = 1;      // 기저값
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    // 결과 출력: fib(n)과 n-2
    printf("%d %d\n", f[n], n - 2);
    return 0;
}
