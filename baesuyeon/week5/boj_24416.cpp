#include <iostream>
using namespace std;

int fibCount = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        fibCount++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    int dp[41];
    dp[1] = dp[2] = 1;
    int count = 0;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    fib(n);
    int dpCount = fibonacci(n);

    cout << fibCount << " " << dpCount << '\n';

    return 0;
}