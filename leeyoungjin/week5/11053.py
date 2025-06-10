# LIS Algorithm

array = []
n = int(input()) # parameter N input
depth = [1] * n

array = list(map(int, input().split())) # 리스트에 input 

for now in range(1,n): # 처음엔 무조건 자기 자신 하나를 넣고 시작하기 때문에 두번째부터 시작
    for before in range(now): # 비교 시작
        if array[before] < array[now]: # 앞 원소가 나보다 크다면
            if depth[now] < depth[before] + 1: 
                depth[now] = depth[before] + 1  # 이전 길이에 now 1개를 더한 값이 더 길다면 긴 값으로 변경
                
# LIS의 길이는 depth에서 가장 큰 값을 의미함
answer = max(depth)
print(answer)
    
    


        










