#include <iostream>
using namespace std;

int arr[1025][1025]; 
int prefix[1025][1025]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                           - prefix[i-1][j-1] + arr[i][j];
        }
    }

    for (int q = 0; q < M; ++q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefix[x2][y2]
                   - prefix[x1-1][y2]
                   - prefix[x2][y1-1]
                   + prefix[x1-1][y1-1];

        cout << result << '\n';
    }

}
