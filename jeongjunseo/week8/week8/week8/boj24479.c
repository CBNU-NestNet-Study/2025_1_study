#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001

// �� �������� �ִ� ���� ���� ������ �ӽ� �迭
int deg[MAXN];

// ���� ����Ʈ�� �ϳ��� �� ���� (���� ����ŭ��)
int edge_pool[MAXN * 2]; // ����� �ִ� 2M
int* adj[MAXN];          // �� �������� ���� ������

int order[MAXN], visited[MAXN], cnt = 1;

// �������� ���Ŀ� �� �Լ�
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

    // 1. ���� ������ŭ ������ �迭 �Ҵ�
    for (int i = 1; i <= n; i++)
        adj[i] = malloc((deg[i] + 1) * sizeof(int)); // �ϴ� 1ĭ, �Ʒ��� ���Ҵ�

    // 2. ���� ���� �Է� (�ϴ� deg�� ����)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++; deg[v]++;
    }

    // 3. �ʿ��� ��ŭ �ٽ� �Ҵ�
    for (int i = 1; i <= n; i++) {
        free(adj[i]);
        adj[i] = malloc(deg[i] * sizeof(int));
        deg[i] = 0; // ī���� �ʱ�ȭ (�ٽ� �� ����)
    }

    // 4. ���� ���� ����
    rewind(stdin); // �ٽ� �Է�
    scanf("%d %d %d", &n, &m, &r); // �ٽ� ����
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
