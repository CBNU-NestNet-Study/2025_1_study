#include <stdio.h>

int N, M;
int arr[1025][1025];  // 입력 배열
int psum[1025][1025]; // 2D 누적합

int main() {
    scanf("%d %d", &N, &M); // N, M 입력

    // 배열 값 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 2D 누적합 계d
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            psum[i][j] = psum[i - 1][j]
                       + psum[i][j - 1]
                       - psum[i - 1][j - 1]
                       + arr[i][j];
        }
    }

    // 질의 처리
    for (int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = psum[x2][y2]
                   - psum[x1 - 1][y2]
                   - psum[x2][y1 - 1]
                   + psum[x1 - 1][y1 - 1];
        printf("%d\n", result);
    }

    return 0;
}
