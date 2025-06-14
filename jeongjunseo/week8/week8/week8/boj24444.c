#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001

int* adj[MAXN];      // 각 정점의 인접 리스트 포인터
int deg[MAXN];       // 각 정점의 간선 개수
int order[MAXN];     // 방문 순서
int visited[MAXN];   // 방문 여부
int queue[MAXN];     // BFS용 큐
int cnt = 1;

int cmp(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    // 1. deg 세기 (필요한 만큼만 malloc)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }

    // 2. 인접리스트 할당
    for (int i = 1; i <= n; i++) {
        adj[i] = malloc(deg[i] * sizeof(int));
        deg[i] = 0; // 다시 0부터 채움
    }

    // 3. 간선 재입력 및 저장
    rewind(stdin); // 입력을 다시 처음으로(온라인저지에서는 불가, 아래처럼 다시 입력받아야 함)
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // 4. 인접리스트 오름차순 정렬
    for (int i = 1; i <= n; i++)
        qsort(adj[i], deg[i], sizeof(int), cmp);

    // 5. BFS
    int front = 0, rear = 0;
    queue[rear++] = r;
    visited[r] = 1;
    order[r] = cnt++;

    while (front < rear) {
        int v = queue[front++];
        for (int i = 0; i < deg[v]; i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = 1;
                order[u] = cnt++;
                queue[rear++] = u;
            }
        }
    }

    // 6. 결과 출력
    for (int i = 1; i <= n; i++)
        printf("%d\n", order[i]);

    // 7. 메모리 해제 (필수 아님, 습관화)
    for (int i = 1; i <= n; i++) free(adj[i]);
    return 0;
}
