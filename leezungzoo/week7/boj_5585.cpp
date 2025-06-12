#include <iostream>
using namespace std;

int main() {
    int price;
    cin >> price;

    int change = 1000 - price;
    int count = 0;
    int coins[] = {500, 100, 50, 10, 5, 1};

    for (int i = 0; i < 6; i++) {
        count += change / coins[i];
        change %= coins[i];
    }

    cout << count << endl;
    return 0;
}
