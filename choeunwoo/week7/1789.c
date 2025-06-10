#include <stdio.h>

int main() {
    long long S, sum = 0;
    int cnt = 0;
    
    scanf("%lld", &S);              // 목표 합 입력
    for (long long i = 1; sum + i <= S; i++) {
        sum += i;                   // 누적 합 계산
        cnt++;                      // 개수 세기
    }
    
    printf("%d\n", cnt);            // 최대 개수 출력
    return 0;
}
