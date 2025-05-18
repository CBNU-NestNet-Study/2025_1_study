#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string>
using namespace std; 

int fib(int n, int &count) {
    if (n == 1 || n == 2) {
        count++;
        return 1;
    } else {
        return fib(n - 1, count) + fib(n - 2, count);
    }
}

int fibonacci(int n, int &count_dp) {
    int* dp = new int[n + 1];
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        count_dp++;
    }
    int result = dp[n];
    delete[] dp;
    return result;
}

int main() {
    int n;
    cin >> n;

    int count_recursive = 0;
    int count_dp = 0;

    fib(n, count_recursive);
    fibonacci(n, count_dp);

    cout << count_recursive << " " << count_dp << '\n';
    return 0;
}
