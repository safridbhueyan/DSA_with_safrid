#include <iostream>
#include <vector>

using namespace std;

int main(){
    int nodes, edges;
    cout << "Enter no of nodes: ";
    cin >> nodes;
    cout << "Enter no of edges: ";
    cin >> edges;

    int graph[nodes][nodes];
    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            graph[i][j] = (i==j)?0:-1;

    for(int i=0;i<edges;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }

    int start = 8;
    vector<int> st_nodes;
    st_nodes.push_back(start);
    vector<bool> visited(nodes, false);
    visited[start] = true;

    int mst_sum = 0;

    while(st_nodes.size() < nodes){
        int mn_e = 99999;
        int mn_p = -1, mn_c = -1;
        for(int i=0;i<st_nodes.size();i++){
            int v1 = st_nodes[i];
            for(int j=0;j<nodes;j++){
                int v2 = j;
                if(graph[v1][v2]>0 && !visited[v2] && graph[v1][v2]<mn_e){
                    mn_e = graph[v1][v2];
                    mn_p = v1;
                    mn_c = v2;
                }
            }
        }

        cout << mn_p << "->" << mn_c << endl;
        mst_sum += mn_e;

        st_nodes.push_back(mn_c);
        visited[mn_c] = true;
    }

    cout << "Total Weight of MST: " << mst_sum;
}