#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1]
                         - prefix[i - 1][j - 1] + A[i][j];
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefix[x2][y2]
                   - prefix[x1 - 1][y2]
                   - prefix[x2][y1 - 1]
                   + prefix[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}
