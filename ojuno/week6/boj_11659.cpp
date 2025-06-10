#include <iostream>
using namespace std;

int arr[100001];
long long sum[100001];
 
int main(void) {
    ios::sync_with_stdio(false); // C와 C++ 입출력 동기화 해제
    cin.tie(NULL);

    int n, m, i, j;
    long long ans;
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
 
    while (m--) {
        cin >> i >> j;
        ans = sum[j] - sum[i - 1];
        cout << ans << '\n';
    }
 
    return 0;
}