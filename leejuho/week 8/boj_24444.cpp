#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];  // 인접 리스트
int visited[MAX];        // 방문 순서 저장
int order = 1;           // 방문 순서 카운터

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order++;  // 시작 노드 방문 순서 저장

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (visited[next] == 0) {  // 방문 안한 노드만 큐에 추가
                visited[next] = order++;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 무방향 그래프
    }

    // 인접 리스트 정렬 (오름차순 보장)
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(R);  // BFS 시작

    // 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
