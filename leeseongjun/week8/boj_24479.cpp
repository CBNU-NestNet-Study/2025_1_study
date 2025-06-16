#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

vector<int> graph[MAX]; // 인접 리스트
int visited[MAX];       // 방문 순서 기록용
int order = 1;          // 방문 순서 카운트

void dfs(int node) {
    visited[node] = order++; // 현재 노드 방문 표시

    for (int next : graph[node]) {
        if (visited[next] == 0) {
            dfs(next); // 방문 안 했으면 계속 탐색
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    // 그래프 입력
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프니까 양방향 추가!
    }

    // 각 정점의 인접 리스트 오름차순 정렬
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(r); // DFS 시작!

    // 방문 순서 출력
    for (int i = 1; i <= n; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
