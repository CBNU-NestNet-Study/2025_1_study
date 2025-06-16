#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int visited[MAX];  // 방문 순서 저장용
int cnt = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = cnt++;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (visited[next] == 0) {
                visited[next] = cnt++;
                q.push(next);
            }
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

    // 오름차순 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(R);

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
