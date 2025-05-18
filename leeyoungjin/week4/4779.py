
def cantor(start, end, arr):
   
    if end - start < 3:
        return  # 구간의 길이가 3보다 작으면 더 이상 나눌 수 없으므로 종료
    
    third = (end - start) // 3  # 현재 구간을 3등분할 크기 계산


    for i in range(start + third, start + 2 * third):  # 가운데 구간을 공백으로 채움
        arr[i] = ' '

 
    cantor(start, start + third, arr)  # 왼쪽 1/3 재귀
    cantor(start + 2 * third, end, arr) # 오른쪽 1/3 재귀귀

# 입력을 계속 받아서 처리 (EOF까지 반복)
while True:
    try:
        n = int(input())              # 칸토어 집합의 단계 입력
        length = 3 ** n               # 최종 문자열의 길이
        result = ['-'] * length       # 전체를 '-'로 초기화
        cantor(0, length, result)     # 칸토어 함수 실행
        print(''.join(result))        # 결과 출력 (문자열 변환)
    except EOFError: 
        break  # 입력이 끝나면 종료
