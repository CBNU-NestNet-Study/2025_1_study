#include <iostream>
using namespace std;

int main() {
    int price;
    cin >> price;

    int change = 1000 - price;  // 거스름돈 계산
    int coins[6] = {500, 100, 50, 10, 5, 1};  // 동전 종류
    int count = 0;  // 사용한 동전의 총 개수

    //  큰 동전부터 차례대로 확인
    for (int i = 0; i < 6; ++i) {
        count += change / coins[i];  // 해당 동전 몇 개 쓸 수 있는지
        change %= coins[i];          // 남은 금액 계산
    }

    cout << count << endl;  // 결과 출력
    return 0;
}
