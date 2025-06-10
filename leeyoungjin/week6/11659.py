import sys
input = sys.stdin.readline

# N: 수의 개수, M: 줄의 개수
N, M = map(int, input().split())
numbers = list(map(int, input().split()))

# 누적합 배열 초기화
prefix_sum = [0] * (N + 1)

# 누적합 계산
for i in range(1, N + 1):
    prefix_sum[i] = prefix_sum[i - 1] + numbers[i - 1]

# 줄 처리
for _ in range(M):
    i, j = map(int, input().split())
    print(prefix_sum[j] - prefix_sum[i - 1])