#include <stdio.h>

int main() {
    int T, N;
    static int rank2[100001];

    scanf("%d", &T);           // 테스트 케이스 수 입력
    while (T--) {
        scanf("%d", &N);       // 지원자 수 입력
        for (int i = 0; i < N; i++) {
            int r1, r2;
            scanf("%d %d", &r1, &r2);
            rank2[r1] = r2;    // 1차 순위 r1에 2차 순위 r2 저장
        }

        int cnt = 0;
        int best = N + 1;     // 지금까지 가장 좋은 2차 순위
        for (int i = 1; i <= N; i++) {
            if (rank2[i] < best) {
                cnt++;         // 2차 순위가 더 좋으면 합격
                best = rank2[i];
            }
        }

        printf("%d\n", cnt);  // 각 테스트 케이스 결과 출력
    }
    return 0;
}
