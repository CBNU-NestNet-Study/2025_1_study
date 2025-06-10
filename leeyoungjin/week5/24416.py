# parameter N < 20 / -> 피보나치 수 구하기 문제
import sys

count_1 = 0 # 1번 코드의 호출 횟수 카운트 변수
count_2 = 0 # 2번 코드의 호출 횟수 카운트 변수

def fibonacci_1(N): # 피보나치 함수를 재귀적으로 만든다
    global count_1
    if N == 0: # 0이면 0
        return 0
    if (N == 1 or N == 2): # 1이면 1
        count_1 += 1
        return 1    
    else: # 1 이상이면 N-1과 N-2를 재귀 호출
        return fibonacci_1(N-1)+fibonacci_1(N-2)

def fibonacci_2(n):
    global count_2 
    if n <= 0:
        return 0
    elif n == 1 or n == 2:
        return 1

    f = [0] * (n + 1)  # 0부터 n까지 저장할 리스트 초기화
    f[1] = f[2] = 1 
    for i in range(3, n + 1): # 1과 2는 했으니까 3부터 n+1까지 / index를 0부터 사용하기 위함
        f[i] = f[i - 1] + f[i - 2]  # 코드2
        count_2 += 1 # count++

    return f[n]

    
n = int(sys.stdin.readline()) # N 입력받기
fibonacci_1(n)
fibonacci_2(n)
print(count_1,count_2) # 프린트 ~~~~~



