//Directed Graph to Adjacency List
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj(V);

    for (auto &it : edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    return adj;
}

int main() {

    int V = 3;
    vector<vector<int>> edges = {{1,0}, {1,2}, {2,0}};

    vector<vector<int>> adj = createGraph(V, edges);

    cout << "Adjacency List Representation:" << endl;
    for(int i=0; i<V; i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}