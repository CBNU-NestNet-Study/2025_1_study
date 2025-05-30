#include <stdio.h>

// 두 수 중 더 큰 값을 반환하는 함수
int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int i, n;
	int input[301]; // 각 계단의 점수 저장
	int dp[301];    // dp[i]: i번째 계단까지 올라갔을 때의 최대 점수

	scanf("%d", &n); // 계단의 개수 입력

	i = 1;
	while (i <= n)
	{
		scanf("%d", &input[i]); // 계단 점수 입력 (1번 인덱스부터 시작)
		i++;
	}

	// 초기 조건 설정
	dp[1] = input[1];                  // 첫 번째 계단 점수
	dp[2] = input[1] + input[2];       // 첫 + 두 번째 계단 점수

	i = 3;
	while (i <= n)
	{
		// 두 가지 경우 중 큰 값을 선택
		// 1) i-2 → i
		// 2) i-3 → i-1 → i
		dp[i] = max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]);
		i++;
	}

	printf("%d", dp[n]); // 마지막 계단까지의 최대 점수 출력
}
