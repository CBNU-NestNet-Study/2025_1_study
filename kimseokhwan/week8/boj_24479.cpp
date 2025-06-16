#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
int visited[MAX];
int order=1;


void dfs(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,r;
    cin>>n>>m>>r;
    for (int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(r);

    for (int i=1;i<=n;i++) {
        cout<<visited[i]<<'\n';
    }

    return 0;
}


void dfs(int node) {
    visited[node] = order++;

    for (int next:graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}
