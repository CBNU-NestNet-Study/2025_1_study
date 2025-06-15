#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> prefix_sum(N + 1, 0);  // prefix_sum[0] = 0

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b] - prefix_sum[a - 1] << '\n';
    }

    return 0;
}
