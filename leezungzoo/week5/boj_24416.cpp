#include <iostream>
using namespace std;

int code1_count = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        code1_count++;
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int fibonacci(int n, int &code2_count) {
    int f[41]; 
    f[1] = f[2] = 1;

    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        code2_count++;
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;

    fib(n); 

    int code2_count = 0;
    fibonacci(n, code2_count); 

    cout << code1_count << " " << code2_count << endl;
    cout << code2_count << " " <<code2_count << endl;
}
