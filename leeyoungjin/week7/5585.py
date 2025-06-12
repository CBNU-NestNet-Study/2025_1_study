N = int(input().strip())  # 물건의 가격 입력
change = 1000 - N         # 1000엔 지폐에서 물건 값을 뺀 거스름돈
count = 0                 # 동전 개수 카운트

# 가장 큰 동전부터 차례로 거슬러 줌
for coin in [500, 100, 50, 10, 5, 1]:
    count += change // coin   # 해당 동전으로 몇 개 거슬러 줄 수 있는지
    change %= coin            # 남은 거스름돈을 갱신

print(count)  # 필요한 최소 동전 개수 출력 ~~~~~
