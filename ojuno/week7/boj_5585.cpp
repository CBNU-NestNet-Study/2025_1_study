#include <iostream>
using namespace std;


int main(){
    // 타로가 지불할 돈
    int n;
    int result = 0;;
    int money[6] = {500, 100, 50, 10, 5, 1};

    cin >> n;

    n = 1000 - n;
    
    for(int i = 0; i < 6; i++){
        result += (n / money[i]);
        n %= money[i];
    }

    cout << result;

    return 0;
}