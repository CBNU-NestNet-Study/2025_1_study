#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector graph[MAX];
int visited[MAX];
int visit_order[MAX];
int queue[MAX];
int front = 0, rear = 0;
int order = 1;

// 벡터 초기화
void init_vector(Vector* v) {
    v->capacity = 2;
    v->size = 0;
    v->data = (int*)malloc(sizeof(int) * v->capacity);
}

// 벡터 삽입
void push_back(Vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = val;
}

// 정렬 비교 함수
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// BFS 함수
void bfs(int start) {
    visited[start] = 1;
    visit_order[start] = order++;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];
        for (int i = 0; i < graph[cur].size; ++i) {
            int next = graph[cur].data[i];
            if (!visited[next]) {
                visited[next] = 1;
                visit_order[next] = order++;
                queue[rear++] = next;
            }
        }
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);

    // 그래프 초기화
    for (int i = 1; i <= N; ++i) {
        init_vector(&graph[i]);
    }

    // 간선 입력
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        push_back(&graph[u], v);
        push_back(&graph[v], u);
    }

    // 각 정점의 인접 정점 정렬 (오름차순)
    for (int i = 1; i <= N; ++i) {
        qsort(graph[i].data, graph[i].size, sizeof(int), cmp);
    }

    // BFS 수행
    bfs(R);

    // 방문 순서 출력
    for (int i = 1; i <= N; ++i) {
        printf("%d\n", visit_order[i]);
    }

    // 메모리 해제
    for (int i = 1; i <= N; ++i) {
        free(graph[i].data);
    }

    return 0;
}