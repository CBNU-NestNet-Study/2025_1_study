#include <iostream>
using namespace std;

int main() {
    long long S;
    cin >> S;

    long long sum = 0;  // 누적 합
    int i = 1;          // 현재 자연수

    //  S를 넘지 않을 때까지 더하기
    while (sum + i <= S) {
        sum += i;
        i++;
    }

    cout << i - 1 << endl;  // 마지막 숫자는 초과하므로 i - 1 출력
    return 0;
}