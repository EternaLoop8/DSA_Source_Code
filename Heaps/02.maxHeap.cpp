#include <bits/stdc++.h>
using namespace std;

// Using recursion
class Solution1 {
public:
    bool isHeapUtil(vector<int> &arr, int i, int n) {
        // If leaf node
        if (i >= n / 2) {
            return true;
        }

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (arr[i] < arr[left]) {
            return false;
        }

        // Check right child only if exists
        if (right < n && arr[i] < arr[right]) {
            return false;
        }

        // Recurse
        return isHeapUtil(arr, left, n) && (right >= n || isHeapUtil(arr, right, n));
    }

    bool isMaxHeap(vector<int> &arr) {
        return isHeapUtil(arr, 0, arr.size());
    }
};

// Using iteration
class Solution2 {
public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // Traverse only internal nodes
        for (int i = 0; i <= (n - 2) / 2; ++i) {
            // Check left child
            if (arr[2 * i + 1] > arr[i]) {
                return false;
            }
            // Check right child (ensure index is valid)
            if (2 * i + 2 < n && arr[2 * i + 2] > arr[i]) {
                return false;
            }
        }
        return true; // Fixed: Moved outside the loop to check all nodes
    }
};

int main() {
    vector<int> arr = {90, 15, 10, 7, 12, 2, 7, 3};

    Solution1 obj1;
    Solution2 obj2;

    cout << "Solution 1 (Recursive): " << (obj1.isMaxHeap(arr) ? "True" : "False") << endl;
    cout << "Solution 2 (Iterative): " << (obj2.isMaxHeap(arr) ? "True" : "False") << endl;

    return 0;
}
