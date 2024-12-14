#include<bits/stdc++.h>
using namespace std;

int main(){
    int node, edge;
    cin>>node>>edge;
    vector<int> adj[node+1];
    for(int i = 0 ; i<edge; i++){
        int input1, input2;
        cin>>input1>>input2;
        adj[input1].push_back(input2);
        adj[input2].push_back(input1);
    }
     cout << "\nAdjacency List:\n";
    for (int i = 1; i <= node; i++) {
        cout << i << " -> ";
        for (auto it : adj[i]) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}