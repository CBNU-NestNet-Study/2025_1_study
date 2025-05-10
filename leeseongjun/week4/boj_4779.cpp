#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void cantor(char line[], int start, int len) {
    if (len == 1) return;
    int part = len / 3;
    for (int i = start + part; i < start + 2 * part; i++) {
        line[i] = ' ';
    }
    cantor(line, start, part);
    cantor(line, start + 2 * part, part);
}

int main() {
    int n;
    while (cin >> n) {
        int len = pow(3, n);
        char line[531442]; // 3^12 + 1
        memset(line, '-', len);
        line[len] = '\0';
        cantor(line, 0, len);
        cout << line << '\n';
    }
}
