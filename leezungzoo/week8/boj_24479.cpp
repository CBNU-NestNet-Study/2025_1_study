#include <iostream>  
#include <vector>   
#include <algorithm> 

using namespace std;

vector<vector<int>> adj; 
vector<int> visited_order;  
int order_counter = 1;            

void dfs(int u) {
    visited_order[u] = order_counter++;
    for (int v : adj[u]) {
        if (visited_order[v] == 0) { 
            dfs(v); 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R; 
    cin >> N >> M >> R;

    adj.resize(N + 1);
    visited_order.resize(N + 1, 0); 

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(R);

    for (int i = 1; i <= N; ++i) {
        cout << visited_order[i] << "\n";
    }

    return 0;
}