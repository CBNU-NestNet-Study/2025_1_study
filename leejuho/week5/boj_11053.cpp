#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cstring>
#include <cmath> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n, 1); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    cout << result << '\n';
    return 0;
}
