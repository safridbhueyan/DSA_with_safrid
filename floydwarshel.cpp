#include<bits/stdc++.h>

using namespace std;

int main(){
    int nodes, edges;
    cout << "Number of nodes: ";
    cin >> nodes;
    cout <<"Number of edges: ";
    cin >> edges;

    int graph[nodes][nodes];
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            graph[i][j] = (i==j)?0:99999;

    cout << "Enter the edges: ";
    for(int i=0;i<edges;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = graph[v2][v1] = w;
    }

    for(int k=0;k<nodes;k++)
        for(int i=0;i<nodes;i++)
            for(int j=0;j<nodes;j++)
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}