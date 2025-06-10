#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // N, M 입력

    int *arr  = (int *)malloc(sizeof(int) * (N + 1)); // 원본 배열
    int *psum = (int *)malloc(sizeof(int) * (N + 1)); // 누적합 배열

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]); // 숫자 입력
    }

    psum[0] = 0;
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + arr[i]; // 누적합 계산d
    }

    for (int q = 0; q < M; q++) {
        int S, E;
        scanf("%d %d", &S, &E);               // 구간 시작/끝 입력
        printf("%d\n", psum[E] - psum[S - 1]); // 구간 합 출
    }

    free(arr);
    free(psum);
    return 0;
}
