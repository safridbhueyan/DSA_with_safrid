#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<int>& vis, vector<int>& dfs, vector<int> adj[]) {
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfsUtil(it, vis, dfs, adj);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
    vector<int> vis(v, 0); // Visited array with size `v` initialized to 0
    vector<int> dfs;
    dfsUtil(0, vis, dfs, adj); // Start DFS from node 0 (assuming 0-indexed graph)
    return dfs;
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
        adj[v].push_back(u); // For undirected graph; remove for directed graph
    }

    vector<int> dfs = dfsOfGraph(v, adj);

    cout << "DFS Traversal of the graph: ";
    for (int node : dfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
