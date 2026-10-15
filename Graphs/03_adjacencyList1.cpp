// Undirected Graph to Adjacency List
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);

        adj[v].push_back(u);
    }
    return adj;
}

int main()
{

    int V = 3;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

    vector<vector<int>> adj = createGraph(V, edges);

    cout << "Adjacency list Representation: " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}