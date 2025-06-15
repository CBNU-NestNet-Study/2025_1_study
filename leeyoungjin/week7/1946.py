import sys
input = sys.stdin.readline  # 빠른 입력을 위한 설정

T = int(input().strip())  # 테스트 케이스 수

for _ in range(T):
    N = int(input().strip())  # 지원자 수
    arr = [tuple(map(int, input().split())) for _ in range(N)]  # (서류, 면접) 순위

    # 서류 순위를 기준으로 오름차순 정렬
    arr.sort(key=lambda x: x[0])

    count = 1  # 서류 1등은 항상 선발
    best_interview_rank = arr[0][1]  # 현재까지 면접 순위 최고값(작을수록 좋음)

    # 두 번째 지원자부터 검사
    for i in range(1, N):
        interview_rank = arr[i][1]
        # 면접 순위가 지금까지 본 것보다 더 좋은 경우 선발
        if interview_rank < best_interview_rank:
            count += 1
            best_interview_rank = interview_rank  # 기준 갱신

    print(count)  # 현재 테스트 케이스의 결과 출력
