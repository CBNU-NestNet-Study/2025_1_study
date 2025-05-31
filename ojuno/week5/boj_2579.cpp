#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> score(n + 1);
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    dp[1] = score[1];
    if (n >= 2) dp[2] = score[1] + score[2];
    if (n >= 3) {
        for (int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
