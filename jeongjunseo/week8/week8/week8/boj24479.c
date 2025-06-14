#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001

// 각 정점마다 최대 간선 수를 저장할 임시 배열
int deg[MAXN];

// 간선 리스트를 하나로 쭉 저장 (간선 수만큼만)
int edge_pool[MAXN * 2]; // 양방향 최대 2M
int* adj[MAXN];          // 각 정점마다 간선 시작점

int order[MAXN], visited[MAXN], cnt = 1;

// 오름차순 정렬용 비교 함수
int cmp(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

void dfs(int v) {
    visited[v] = 1;
    order[v] = cnt++;
    for (int i = 0; i < deg[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) dfs(u);
    }
}

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    // 1. 간선 개수만큼 포인터 배열 할당
    for (int i = 1; i <= n; i++)
        adj[i] = malloc((deg[i] + 1) * sizeof(int)); // 일단 1칸, 아래서 재할당

    // 2. 간선 정보 입력 (일단 deg만 세기)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++; deg[v]++;
    }

    // 3. 필요한 만큼 다시 할당
    for (int i = 1; i <= n; i++) {
        free(adj[i]);
        adj[i] = malloc(deg[i] * sizeof(int));
        deg[i] = 0; // 카운터 초기화 (다시 쓸 예정)
    }

    // 4. 실제 간선 저장
    rewind(stdin); // 다시 입력
    scanf("%d %d %d", &n, &m, &r); // 다시 읽음
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }
    for (int i = 1; i <= n; i++) qsort(adj[i], deg[i], sizeof(int), cmp);

    dfs(r);

    for (int i = 1; i <= n; i++)
        printf("%d\n", order[i]);
    return 0;
}
