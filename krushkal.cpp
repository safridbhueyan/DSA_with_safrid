#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int>& parent) {
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent); 
}

void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e; 

    vector<tuple<int, int, int>> edges; 
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({weight, u, v});
    }

    sort(edges.begin(), edges.end()); 

    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0); 

    int mstWeight = 0;
    vector<pair<int, int>> mst; 

    for (auto& edge : edges) {
        int weight, u, v;
        tie(weight, u, v) = edge; 
        if (findParent(u, parent) != findParent(v, parent)) {
            mstWeight += weight;
            mst.push_back({u, v});
            unionNodes(u, v, parent, rank);
        }
    }

    cout << "MST Weight: " << mstWeight << "\nEdges in MST:\n";
    for (auto& edge : mst)
        cout << edge.first << " - " << edge.second << "\n";

    return 0;
}
