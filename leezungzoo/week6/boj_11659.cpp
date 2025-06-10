#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N + 1, 0);       
    vector<int> prefixSum(N + 1, 0);  

    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (int q = 0; q < M; ++q) {
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << '\n';
    }

}
