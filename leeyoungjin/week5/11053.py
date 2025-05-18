# LIS Algorithm

array = []
n = int(input()) # parameter N input
depth = [1] * n

array = list(map(int, input().split())) # 리스트에 input 

for now in range(1,n): # 맨처음엔 무조건 자기자신 하나이기 때문에 두번째부터 시작
    for before in range(now): # 자기 자신의 앞에 있는 것들하고 비교해 나감
        # 증가하는 값이라면
        if array[before] < array[now]: 
            # 이전 길이에 now 1개를 더한 값이 더 길다면 긴 값으로 변경
            if depth[now] < depth[before] + 1: 
                depth[now] = depth[before] + 1
                
# LIS의 길이는 depth에서 가장 큰 값을 의미함
answer = max(depth)
print(answer)
    
    


        










