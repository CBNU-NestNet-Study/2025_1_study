#include <iostream>
using namespace std;

int N, K, cnt = 0, result = -1;
int A[500001], tmp[500001];

void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];
    i = p; t = 0;
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K) result = A[i - 1];
    }
}

void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    merge_sort(A, 0, N - 1);
    cout << result << endl;
}