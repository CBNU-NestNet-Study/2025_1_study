#include <iostream>
#include <vector>
using namespace std;

int count_1 = 0;
int count_2 = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        count_1++;  
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    vector<int> f(n + 1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        count_2++;  // 코드2 실행 횟수
    }
    return f[n];
}



int main(){
    int n;

    cin >> n;
    fib(n);
    fibonacci(n);
    cout << count_1 << " " << count_2 << '\n';
    return 0;


}


