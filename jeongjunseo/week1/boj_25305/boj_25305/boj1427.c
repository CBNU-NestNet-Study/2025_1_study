#include <stdlib.h>
int compare(const int* a, const int* b) {
    return -(*a - *b);
}
int main() {
    int num;
    int arr[10];
    scanf("%d", &num);
    int i;
    for (i = 0; i < 10;i++) {
        arr[i] = num % 10;
        num /= 10;
        if (num < 1)
            break;
    }
    qsort(arr, i + 1, sizeof(int), compare);
    for (int j = 0;j <= i;j++)
        printf("%d", arr[j]);

    return 0;
}