#include <stdio.h>

int main()
{
	int n;
	int dp[1001] = {0, };       // dp[i]: i번째 수를 마지막 원소로 하는 LIS의 길이
	int input[1001] = {0, };    // 수열 입력을 저장할 배열
	int max = 0;                // 전체 LIS 중 최댓값 저장

	scanf("%d", &n);           // 수열 길이 입력
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]); // 수열 요소 입력

		for (int j = 0; j < i; j++) // 이전 모든 항 j에 대해
		{
			if (input[i] > input[j]) // 현재 값이 이전 값보다 크면 증가 수열 조건 만족
			{
				if (dp[i] < dp[j] + 1) // dp[j]를 확장한 것이 더 길다면
				{
					dp[i] = dp[j] + 1; // i번째 수를 마지막으로 하는 LIS 갱신
					
					if (max < dp[i])   // 최댓값 갱신
						max = dp[i];
				}
			}
		}
	}
	printf("%d", max); // 가장 긴 증가하는 부분 수열의 길이 출력
}