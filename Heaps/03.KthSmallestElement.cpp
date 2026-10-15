// Given an integer array arr[] and k. Find the k'th smallest element in the given array.
// Note: k is always smaller than the size of the array.

#include <bits/stdc++.h>
using namespace std;

// Using Sorting (TC: O(n log(n)); SC: O(1))
class Solution1
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        // Sort the given vector
        sort(arr.begin(), arr.end());

        // Return k'th element in the sorted vector
        return arr[k - 1];
    }
};

// Using Max-Heap (TC: O(n*log(k)); SC: O(k))
class Solution2
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        // Create a max heap
        priority_queue<int> pq;

        // Iterate through the array elements
        for (int i = 0; i < arr.size(); ++i)
        {
            // Push the current element onto the max heap
            pq.push(arr[i]);

            // If the size of the max heap exceeds k, remove the largest element
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    Solution1 obj1;
    Solution2 obj2;

    cout << obj1.kthSmallest(arr, k) << endl;
    cout << obj2.kthSmallest(arr, k) << endl;

    return 0;
}