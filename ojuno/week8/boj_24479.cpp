#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
bool visited[MAX];
int order[MAX];
int cnt = 1;

void dfs(int v) {
    visited[v] = true;
    order[v] = cnt++;

    for (int next : graph[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    // 간선 입력
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 무방향 그래프
    }

    // 오름차순 방문을 위해 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << order[i] << '\n';
    }

    return 0;
}
