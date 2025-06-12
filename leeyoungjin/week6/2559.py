# 누적합 대신 컴네의 슬라이딩 윈도우 개념을 활용해보자

n, k = map(int, input().split()) # parameter 받기
temps = list(map(int, input().split())) 

# 처음 k일의 합을 초기값으로 설정
current_sum = sum(temps[:k])
max_sum = current_sum

# 슬라이딩 윈도우
for i in range(k, n):
    current_sum = current_sum - temps[i - k] + temps[i]
    max_sum = max(max_sum, current_sum)

print(max_sum)
