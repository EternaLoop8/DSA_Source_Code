#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper: returns true if a knows b
    bool knows(vector<vector<int>>& M, int a, int b, int n) {
        return M[a][b] == 1;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Step 1: Push all candidates into stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (knows(M, a, b, n)) {
                // If a knows b, a cannot be celebrity
                s.push(b);
            } else {
                // If a does not know b, b cannot be celebrity
                s.push(a);
            }
        }

        // Step 3: Verify the last candidate
        int ans = s.top();

        // Row check: celebrity knows nobody
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 1) {
                return -1; // celeb shouldn't know anyone
            }
        }

        // Column check: everyone knows celebrity
        for (int i = 0; i < n; i++) {
            if (i != ans && M[i][ans] == 0) {
                return -1; // everyone must know celeb
            }
        }

        return ans;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
    return 0;
}