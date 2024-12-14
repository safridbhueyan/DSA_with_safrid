#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> vis(v, 0); 
    vis[0] = 1;           
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<int> adj[v];
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> bfs = bfsOfGraph(v, adj);

    cout << "BFS Traversal of the graph: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
