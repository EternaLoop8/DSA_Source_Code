#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
private:
    // Helper: find next smaller element indexes
    vector<int> nextSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Helper: find previous smaller element indexes
    vector<int> prevSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Largest rectangle in histogram
    int largestRectangleArea(int* heights, int n) {
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int h = heights[i];

            // If no smaller element on right, set boundary to n
            if (next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int newArea = h * width;
            area = max(area, newArea);
        }
        return area;
    }

public:
    // Maximal rectangle of 1’s in a binary matrix
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Step 1: Compute area for the first row
        int area = largestRectangleArea(M[0], m);

        // Step 2: Update row-wise (histogram build-up)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Add heights if current cell is 1
                if (M[i][j] != 0)
                    M[i][j] += M[i - 1][j];
                else
                    M[i][j] = 0;
            }
            // Step 3: Compute area for this updated row
            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;
    }
};

// Driver code
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }

        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
    return 0;
}