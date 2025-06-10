#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int max = sum;

    for (int i = k; i < n; i++) {
        sum = sum - arr[i - k] + arr[i];
        if (sum > max)
            max = sum;
    }

    printf("%d\n", max);

    free(arr);
    return 0;
}
