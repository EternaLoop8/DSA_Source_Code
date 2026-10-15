/*Given an integer array arr[] of size n elements and a positive integer K, the task is to return the kth largest element in the given array (not the Kth distinct element).
Examples:
Input:  [1, 23, 12, 9, 30, 2, 50], K = 3
Output: 23
*/

#include <bits/stdc++.h>
using namespace std;

// Using Sorting (TC: O(n log(n)); SC: O(1))
class Solution1{
public:
    int kthLargest(vector<int>& arr, int k){
        // Sort array in descendng order
        sort(arr.begin(), arr.end(), greater<int>());

        return arr[k-1];
    }
};

// Using Priority Queue(Min-Heap) - (TC:O(n*log(k)); SC:O(k))
class Solution2{
public:
    int kthLargest(vector<int> arr, int k){
        int n = arr.size();

        // Create a min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; ++i){
            // Push current element onto the min heap
            pq.push(arr[i]);

            // If size of min heap exceeds k, remove the largest element
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main() {
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 3;

    Solution1 obj1;
    Solution2 obj2;

    cout << obj1.kthLargest(arr, k) << endl;
    cout << obj2.kthLargest(arr, k) << endl;
    
    return 0;
}