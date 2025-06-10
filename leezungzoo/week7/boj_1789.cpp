#include <iostream>
using namespace std;

int main() {
    long long S;
    cin >> S;

    long long sum = 0;
    int N = 0;

    for (int i = 1; ; i++) {
        sum += i;
        if (sum > S) break;
        N++;
    }

    cout << N << endl;
    return 0;
}
