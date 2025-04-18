#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000  // 스택의 최대 크기 정의
int stack[MAX];     // 정적 배열로 스택 구현

int main(void) {
    int n, cmd, x;
    scanf("%d", &n);  // 명령어 개수 입력

    int idx = 0;  // 스택의 현재 크기 (다음에 들어갈 위치)

    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);

        // 명령어에 따른 처리
        switch (cmd) {
            case 1:  // push x: 스택에 x 추가
                scanf("%d", &x);

                // 스택에 공간이 있는 경우
                if (idx < MAX) {
                    stack[idx] = x;
                    idx++;  // 다음 삽입 위치로 이동
                } else {
                    // 최대 크기 초과 시 에러 출력
                    printf("Stack overflow\n");
                }
                break;

            case 2:  // pop: 스택에서 top 제거 및 출력
                if (idx <= 0) {
                    printf("-1\n");  // 스택이 비어 있음
                } else {
                    printf("%d\n", stack[idx - 1]);  // top 값 출력
                    idx--;  // top 제거
                }
                break;

            case 3:  // size: 스택에 있는 요소 개수 출력
                printf("%d\n", idx);
                break;

            case 4:  // empty: 스택이 비어 있으면 1, 아니면 0 출력
                if (idx == 0) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
                break;

            case 5:  // top: 스택의 top 값 출력 (삭제 X)
                if (idx == 0) {
                    printf("-1\n");  // 비어 있는 경우
                } else {
                    printf("%d\n", stack[idx - 1]);  // top 값만 출력
                }
                break;

            default:  // 유효하지 않은 명령 방지
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}


