// DFS for a disconnected undirectd graph
#include <bits/stdc++.h>
using namespace std;

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res){
    visited[s] = true;

    res.push_back(s);

    for(int i : adj[s]){
        if(visited[i] == false)
        dfsRec(adj, visited, i, res);
    }
}

vector<int> dfs(vector<vector<int>> &adj){
    vector<bool>  visited(adj.size(), false);
    vector<int> res;

    for(int i=0; i<adj.size(); i++){
        if(visited[i] == false)
        dfsRec(adj, visited, i, res);
    }
    return res;
}

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 6; 
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 5, 4);

    vector<int> res = dfs(adj);

    for(auto it : res){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}