#include <stdio.h>
#include <stdlib.h>

// 덱(Deque) 구조체 정의
typedef struct Deque {
    int front;      // 덱의 앞쪽 인덱스
    int rear;       // 덱의 뒤쪽 인덱스
    int size;       // 덱 배열의 크기
    int* data;      // 데이터를 저장하는 동적 배열
} Deque;

// 덱 초기화 함수
void DequeInit(Deque* pd, int n) {
    pd->front = pd->rear = 0;
    pd->size = n + 1;  // 실제 사용할 크기보다 하나 크게 설정 (원형 큐 방식)
    pd->data = (int*)malloc((n + 1) * sizeof(int));
}

// 덱이 비었는지 확인하는 함수
int DequeIsEmpty(Deque* pd) {
    return (pd->rear == pd->front);
}

// 덱의 앞쪽에 요소 추가
void AddFront(Deque* pd, int data) {
    pd->front = (pd->front - 1 + pd->size) % pd->size;  // 앞쪽 인덱스 감소 (원형 배열이므로 mod 연산)
    pd->data[pd->front] = data;
}

// 덱의 뒤쪽에 요소 추가
void AddRear(Deque* pd, int data) {
    pd->data[pd->rear] = data;
    pd->rear = (pd->rear + 1) % pd->size;  // 뒤쪽 인덱스 증가
}

// 덱의 앞쪽에서 요소 삭제 및 반환
int DelFront(Deque* pd) {
    if (DequeIsEmpty(pd))
        return -1;  // 비어있으면 -1 반환

    int temp = pd->data[pd->front];       // 삭제할 데이터 저장
    pd->front = (pd->front + 1) % pd->size;  // 앞쪽 인덱스 증가
    return temp;
}

// 덱의 뒤쪽에서 요소 삭제 및 반환
int DelRear(Deque* pd) {
    if (DequeIsEmpty(pd))
        return -1;  // 비어있으면 -1 반환

    pd->rear = (pd->rear - 1 + pd->size) % pd->size;  // 뒤쪽 인덱스 감소
    return pd->data[pd->rear];
}

// 덱의 현재 요소 개수 반환
int SizeDeque(Deque* pd) {
    return (pd->rear - pd->front + pd->size) % pd->size;
}

// 덱의 앞쪽 요소 확인
int GetFront(Deque* pd) {
    if (DequeIsEmpty(pd))
        return -1;

    return pd->data[pd->front];
}

// 덱의 뒤쪽 요소 확인
int GetRear(Deque* pd) {
    if (DequeIsEmpty(pd))
        return -1;

    return pd->data[(pd->rear - 1 + pd->size) % pd->size];
}

// 메인 함수
int main(void) {
    int n, cmd, x;
    scanf("%d", &n);  // 명령의 개수 입력

    Deque dq;
    DequeInit(&dq, n);  // 덱 초기화

    // n개의 명령어 실행
    while (n--) {
        scanf("%d", &cmd);
        switch (cmd) {
        case 1:
            scanf("%d", &x);      // 앞쪽에 삽입
            AddFront(&dq, x);
            break;
        case 2:
            scanf("%d", &x);      // 뒤쪽에 삽입
            AddRear(&dq, x);
            break;
        case 3:
            printf("%d\n", DelFront(&dq));  // 앞쪽 요소 삭제 및 출력
            break;
        case 4:
            printf("%d\n", DelRear(&dq));   // 뒤쪽 요소 삭제 및 출력
            break;
        case 5:
            printf("%d\n", SizeDeque(&dq));  // 덱 크기 출력
            break;
        case 6:
            printf("%d\n", DequeIsEmpty(&dq));  // 비었는지 출력
            break;
        case 7:
            printf("%d\n", GetFront(&dq));  // 앞쪽 요소 확인
            break;
        case 8:
            printf("%d\n", GetRear(&dq));   // 뒤쪽 요소 확인
            break;
        }
    }

    free(dq.data);  // 동적 메모리 해제
    return 0;
}
