#include <iostream>
#include <vector>
using namespace std;

int main() {
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

    int maxSum = sum;

    for (int i = K; i < N; ++i) {
        sum = sum - temps[i - K] + temps[i];
        if (sum > maxSum)
            maxSum = sum;
    }

    cout << maxSum << endl;
}
