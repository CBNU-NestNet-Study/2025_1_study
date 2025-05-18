#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> dp(n, 1);  // 모든 dp 값을 1로 초기화

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열 중 최대값이 정답
    int lis_length = *max_element(dp.begin(), dp.end());
    cout << lis_length << endl;

    return 0;
}
