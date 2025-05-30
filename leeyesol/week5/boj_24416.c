#define _CRT_SECURE_NO_WARNINGS // scanf 함수 사용 시 보안 경고를 방지하기 위한 매크로
#include<stdio.h>

// 피보나치 수를 저장할 배열, 초기값으로 f[0]=0, f[1]=1, f[2]=1 설정
int f[41] = { 0,1,1 };

// 재귀 방식과 DP 방식 각각의 호출 횟수를 저장하는 변수
int cnt1 = 0; // 재귀 방식의 fib 함수가 1 또는 2일 때 호출된 횟수 (기저 조건 실행 횟수)
int cnt2 = 0; // DP 방식에서 실제로 계산이 수행된 횟수

// 재귀 방식으로 피보나치 수를 계산하는 함수
int fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++; // n이 1 또는 2일 때 cnt1 증가
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2)); // 재귀 호출을 통해 피보나치 계산
}

// 동적 계획법(DP) 방식으로 피보나치 수를 계산하는 함수
int fibo(int n) {
    for (int i = 3; i <= n; i++) {
        cnt2++; // 새로 계산할 때마다 cnt2 증가
        f[i] = f[i - 1] + f[i - 2]; // 이전 두 항을 더해서 저장
    }
    return f[n]; // 계산된 결과 반환
}

int main() {
    int n;
    scanf("%d", &n); // 사용자로부터 n 입력 받기

    fib(n);  // 재귀 방식으로 피보나치 수 계산 (단, 결과는 사용하지 않고 cnt1만 측정)
    fibo(n); // 동적 계획법 방식으로 피보나치 수 계산 (cnt2 측정)

    printf("%d %d", cnt1, cnt2); // 각 방식의 계산 횟수 출력
	return 0;
}
