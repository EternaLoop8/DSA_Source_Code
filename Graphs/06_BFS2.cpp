// BFS of a Disconnected Undirected Graph
#include <bits/stdc++.h>
using namespace std;

void bfsConnected(vector<vector<int>> &adj, int src, vector<bool> &visited, vector<int> &res)
{
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfsConnected(adj, i, visited, res);
        }
    }
    return res;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 2);

    vector<int> res = bfs(adj);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}