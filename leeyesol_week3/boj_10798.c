#include <stdio.h>

#define MAX_SIZE 15  // 각 줄의 최대 글자 수 (문자열 길이 제한)

// 5줄의 문자열을 저장할 배열
char str_read[5][MAX_SIZE];

int main() {
    int i, j;

    // 문자열 5줄 입력받기
    for (i = 0; i < 5; i++) {
        scanf("%s", str_read[i]);  // 각 줄마다 문자열 입력
    }

    // 세로로 읽기: 열 기준으로 바깥 루프
    for (j = 0; j < MAX_SIZE; j++) {
        for (i = 0; i < 5; i++) {
            // 해당 위치에 문자가 있으면 출력
            if (str_read[i][j] == '\0')  // 문자열 끝을 만나면
                continue;               // 출력 생략
            else
                printf("%c", str_read[i][j]);
        }
    }

    printf("\n");
    return 0;
}
