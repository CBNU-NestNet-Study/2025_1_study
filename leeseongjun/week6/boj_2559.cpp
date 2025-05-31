#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> temp(n);
    for (int i = 0; i < n; ++i)
        cin >> temp[i];

    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += temp[i];

    int maxSum = sum;

    for (int i = k; i < n; ++i) {
        sum = sum - temp[i - k] + temp[i];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << "\n";
    return 0;
}
