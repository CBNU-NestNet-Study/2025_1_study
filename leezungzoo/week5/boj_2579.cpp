#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stair(n);
    for (int i = 0; i < n; i++)
        cin >> stair[i];

    vector<int> dp(n);

    dp[0] = stair[0];
    if (n >= 2) dp[1] = stair[0] + stair[1];
    if (n >= 3) dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}
