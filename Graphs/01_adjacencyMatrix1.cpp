//Undirected Graph to Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges) {
    vector<vector<int>> mat(V, vector<int>(V, 0));

    for (auto &it : edges){
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;

        mat[v][u] = 1;
    }
    return mat;
}

int main() {
    int V = 3;

    vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}};

    vector<vector<int>> mat = createGraph(V, edges);

    cout << "Adjacency Matrix Representation: " << endl;
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}