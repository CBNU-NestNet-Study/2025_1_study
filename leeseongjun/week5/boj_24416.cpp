#include <iostream>
using namespace std;

int count_code1 = 0; 
int count_code2 = 0; 

int fib(int n) {
    if (n == 1 || n == 2) {
        count_code1++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    int f[41];
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        count_code2++;
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;

    fib(n);       
    fibonacci(n);  

    cout << count_code1 << " " << count_code2 << "\n";
    return 0;
}