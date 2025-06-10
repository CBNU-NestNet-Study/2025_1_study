import sys


input = sys.stdin.read
data = input().split() # 입력 데이터를 공백 기준으로 나누어 리스트에 저장

# 첫 번째와 두 번째 입력값은 행렬의 크기 n과 줄의 수 m
n = int(data[0]) # 행렬의 크기 (n x n)
m = int(data[1]) # 줄

matrix = [[0] * (n + 1) for _ in range(n + 1)] # 원본 행렬
prefix = [[0] * (n + 1) for _ in range(n + 1)] # 누적합 행렬

# data 리스트에서 행렬의 원소를 읽어오기 위한 인덱스 초기화
# data[0]은 n, data[1]은 m이므로, 실제 행렬 데이터는 data[2]부터 시작합니다.
index = 2


for i in range(1, n + 1): # 행 (1부터 n까지)
    for j in range(1, n + 1): # 열 (1부터 n까지)
        # data 리스트에서 다음 원소를 정수로 변환하여 matrix[i][j]에 저장
        matrix[i][j] = int(data[index])
        index += 1 # 다음 데이터 원소를 가리키도록 인덱스 증가
        
        # 누적합 계산
        # prefix[i][j]는 (1,1)부터 (i,j)까지의 직사각형 영역의 합을 의미합니다.
        # 점화식: prefix[i][j] = (위쪽까지의 누적합) + (왼쪽까지의 누적합) - (겹치는 부분의 누적합) + (현재 값)
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j]

# 줄줄의 처리
results = [] 
for _ in range(m): 
    # M에서 주어지는 직사각형의 좌상단 좌표 (x1, y1)와 우하단 좌표 (x2, y2)
    x1 = int(data[index])
    y1 = int(data[index + 1])
    x2 = int(data[index + 2])
    y2 = int(data[index + 3])
    index += 4 # 4개의 좌표값을 읽었으므로 인덱스 4 증가

    # 누적합을 이용하여 (x1, y1)부터 (x2, y2)까지의 직사각형 영역의 합을 계산.
    total = (
        prefix[x2][y2]  
        - prefix[x1 - 1][y2] 
        - prefix[x2][y1 - 1] 
        + prefix[x1 - 1][y1 - 1]
    )
    results.append(str(total)) # 계산된 합을 문자열로 변환하여 results 리스트에 추가

print("\n".join(results))