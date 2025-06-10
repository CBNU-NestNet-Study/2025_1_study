#include <stdlib.h>
//qsort함수 기준함수
int compare(const int* a, const int* b) {
    return(*a - *b);    //return값이 양수이면 qsort함수가 두 수의 자리를 바꾸고, 음수이면 자리를 바꾸지 않음.
}
int main() {
    int N, k;
    int score[1000];
    scanf("%d %d", &N, &k);

    for (int i = 0;i < N;i++) {
        scanf("%d", &score[i]);
    }

    qsort(score, N, sizeof(int), compare);

    printf("%d", score[N - k]);
}