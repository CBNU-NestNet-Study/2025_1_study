#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];  // 인접 리스트
int visited[MAX];        // 방문 순서 저장
int cnt = 1;             // 방문 순서 카운트

// DFS 함수
void dfs(int node) {
    visited[node] = cnt++;  // 현재 노드 방문 순서 저장
    for (int next : graph[node]) {
        if (visited[next] == 0) {  // 방문 안 했으면
            dfs(next);             // DFS 호출
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    // 간선 입력 받기
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 양방향 그래프
    }

    // 인접 정점 오름차순 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 시작
    dfs(R);

    // 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
