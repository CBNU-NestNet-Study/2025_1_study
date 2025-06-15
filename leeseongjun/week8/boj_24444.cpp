#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];
int visited[MAX];
int order = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order++;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (visited[next] == 0) {
                visited[next] = order++;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    for (int i = 1; i <= n; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}
