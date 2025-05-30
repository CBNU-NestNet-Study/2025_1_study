#define _CRT_SECURE_NO_WARNINGS         // Visual Studio에서 scanf 보안 경고 제거
#pragma warning(disable: 4996)          // 4996번 경고 무시

#include <stdio.h>

// 최대 크기 1024 x 1024인 배열 선언 (1-based index 사용)
int arr[1025][1025];

int main(void)
{
    int N, M;
    int x1, x2, y1, y2;

    // N: 배열의 크기 (N x N), M: 질의 개수
    scanf("%d %d", &N, &M);

    // 배열 입력 받기 (1-based index)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // 1단계: 각 열에 대해 누적합 계산 (세로 방향 누적)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = arr[i][j] + arr[i - 1][j];
        }
    }

    // 2단계: 각 행에 대해 누적합 계산 (가로 방향 누적)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = arr[i][j] + arr[i][j - 1];
        }
    }

    // M개의 질의 처리: (x1, y1)부터 (x2, y2)까지의 부분 합 계산
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // 누적합 배열을 이용한 2차원 부분합 공식:
        // 전체 합 - 위쪽 - 왼쪽 + 겹치는 부분 한 번 더 뺀 거 다시 더하기
        printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
    }

    return 0;
}