#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** arr = (int**)malloc((n + 1) * sizeof(int*));
    int** sum = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        arr[i] = (int*)malloc((n + 1) * sizeof(int));
        sum[i] = (int*)calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int q = 0; q < m; q++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        printf("%d\n", ans);
    }
}
