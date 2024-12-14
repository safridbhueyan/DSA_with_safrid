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

    vector<bool> visited(nodes, false);
    vector<int> d(nodes, 99999);

    int source;
    cout << "Enter source: ";
    cin >> source;
    d[source] = 0;

    while(true){
        int min_d=99999, min_n=-1;

         for(int i=0;i<nodes;i++){
            if(!visited[i] && d[i]<min_d){
                min_d = d[i];
                min_n = i;
            }
         }

         if(min_n == -1)
            break;

        visited[min_n] = true;

        // Update nodes adjacent to min_n
        for(int adj=0;adj<nodes;adj++){
            if(!visited[adj])
                d[adj] = min(d[adj], d[min_n]+graph[min_n][adj]);
        }
    }

    cout << "Shortest path length from source: ";
    for(int i=0;i<nodes;i++)
        cout << d[i] << " ";

}