#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001

int* adj[MAXN];      // �� ������ ���� ����Ʈ ������
int deg[MAXN];       // �� ������ ���� ����
int order[MAXN];     // �湮 ����
int visited[MAXN];   // �湮 ����
int queue[MAXN];     // BFS�� ť
int cnt = 1;

int cmp(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    // 1. deg ���� (�ʿ��� ��ŭ�� malloc)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }

    // 2. ��������Ʈ �Ҵ�
    for (int i = 1; i <= n; i++) {
        adj[i] = malloc(deg[i] * sizeof(int));
        deg[i] = 0; // �ٽ� 0���� ä��
    }

    // 3. ���� ���Է� �� ����
    rewind(stdin); // �Է��� �ٽ� ó������(�¶������������� �Ұ�, �Ʒ�ó�� �ٽ� �Է¹޾ƾ� ��)
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // 4. ��������Ʈ �������� ����
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

    // 6. ��� ���
    for (int i = 1; i <= n; i++)
        printf("%d\n", order[i]);

    // 7. �޸� ���� (�ʼ� �ƴ�, ����ȭ)
    for (int i = 1; i <= n; i++) free(adj[i]);
    return 0;
}
