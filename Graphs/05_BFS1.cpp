// BFS of a Connected Undirected Graph
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;

    queue<int> q;

    int src = 0;
    visited[src] = true;
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int x : adj[curr]) {
            if (!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 5;
    vector<vector<int>>adj(V);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    vector<int> res = bfs(adj);

    for(int i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}