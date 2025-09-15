#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
private:
    // next smaller element (right side)
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
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

    // previous smaller element (left side)
    vector<int> prevSmallerElement(vector<int> &arr, int n) {
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

public:
    // largest rectangle area in histogram
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            if (next[i] == -1) next[i] = n; // handle edge
            int width = next[i] - prev[i] - 1;
            int newArea = height * width;
            area = max(area, newArea);
        }
        return area;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> heights[i];

    cout << "Largest Rectangle Area = " 
         << sol.largestRectangleArea(heights) << endl;

    return 0;
}