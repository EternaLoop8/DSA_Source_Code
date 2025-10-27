#include <iostream>
#include <vector>
using namespace std;

// Check if (x,y) is a valid move inside the maze
bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to find path from (x,y) to bottom-right corner
bool solveMazeUtil(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<vector<int>> &path)
{
    // If destination is reached, mark path and return true
    if (x == n - 1 && y == n - 1)
    {
        path[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, n, maze, visited))
    {
        visited[x][y] = 1; // mark cell visited
        path[x][y] = 1;    // include in path

        // Move right
        if (solveMazeUtil(x, y + 1, n, maze, visited, path))
            return true;

        // Move down
        if (solveMazeUtil(x + 1, y, n, maze, visited, path))
            return true;

        // Backtrack
        path[x][y] = 0;
        visited[x][y] = 0;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter maze size (n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter maze matrix (0=blocked, 1=open):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> path(n, vector<int>(n, 0));

    if (solveMazeUtil(0, 0, n, maze, visited, path))
    {
        cout << "Path found:\n";
        for (auto &row : path)
        {
            for (int cell : row)
                cout << cell << " ";
            cout << "\n";
        }
    }
    else
    {
        cout << "No path exists\n";
    }

    return 0;
}
