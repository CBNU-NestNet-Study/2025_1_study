#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];          // 인접 리스트
int visited_order[MAX];  // 방문 순서
int visited[MAX];        // 방문 여부
int order = 1;

// 연결 리스트에 노드 추가
void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

// 연결 리스트 정렬 (선택 정렬 방식)
void sort_adj_list(int n) {
    for (int i = 1; i <= n; i++) {
        Node* head = adj[i];
        Node* curr1 = head;

        while (curr1 != NULL) {
            Node* min_node = curr1;
            Node* curr2 = curr1->next;

            while (curr2 != NULL) {
                if (curr2->vertex < min_node->vertex)
                    min_node = curr2;
                curr2 = curr2->next;
            }

            if (min_node != curr1) {
                int temp = curr1->vertex;
                curr1->vertex = min_node->vertex;
                min_node->vertex = temp;
            }

            curr1 = curr1->next;
        }
    }
}

// DFS 함수
void DFS(int v) {
    visited[v] = 1;
    visited_order[v] = order++;

    Node* curr = adj[v];
    while (curr != NULL) {
        int next = curr->vertex;
        if (!visited[next])
            DFS(next);
        curr = curr->next;
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    sort_adj_list(N);
    DFS(R);

    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited_order[i]);
    }

    return 0;
}