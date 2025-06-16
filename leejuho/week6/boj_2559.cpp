#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> temps(N);
    for (int i = 0; i < N; ++i) {
        cin >> temps[i];
    }

    int sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += temps[i];
    }

    int max_sum = sum;

    for (int i = K; i < N; ++i) {
        sum = sum - temps[i - K] + temps[i];
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << '\n';
    return 0;
}
