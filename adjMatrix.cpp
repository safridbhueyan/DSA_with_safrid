#include<bits/stdc++.h>
using namespace std;

int main(){
    int node, edge;
    cin>>node>>edge;
    int adj[node+1][node+1] = {0};
    for(int i = 0 ; i<edge; i++){
        int input1, input2;
        cin>>input1>>input2;
        adj[input1][input2] = 1;
        adj[input2][input1] = 1;
    }
     cout << "\nAdjacency Matrix:\n   ";
    for (int i = 1; i <= node; i++) {
        cout << i << " "; 
    }
    cout << "\n";

    for (int i = 1; i <= node; i++) {
        cout << i << " "; // Print row label
        for (int j = 1; j <= node; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}