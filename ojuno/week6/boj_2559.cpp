#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    int m = -100001;
    int arr[100001];
    int sum[100004];

    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = k; i <= n; i++){
        m = max(m, sum[i] - sum[i - k]);
    }

    cout << m;

    
}