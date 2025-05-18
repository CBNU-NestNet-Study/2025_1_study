#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> lis; // 가상의 LIS 저장

    for (int i = 0; i < n; i++) {
        int x = A[i];
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) {
            lis.push_back(x); // 가장 큰 값이면 추가
        } else {
            *it = x; // 그 자리에 덮어씀
        }
    }

    cout << lis.size() << '\n'; // LIS 길이 출력
    return 0;
}