/*
Heap Sort for decreasing order using min heap

Given an array of elements, sort the array in decreasing order using min heap.

Examples:
Input : arr[] = {5, 3, 10, 1}
Output : arr[] = {10, 5, 3, 1}

Input : arr[] = {1, 50, 100, 25}
Output : arr[] = {100, 50, 25, 1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Using Min Heap Implementation (TC: O(n log n))
    void heapify(vector<int> &arr, int n, int i)
    {
        int smallest = i;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        // If left child is smaller than root
        if (l < n && arr[l] < arr[smallest])
        {
            smallest = l;
        }

        // If right child is smaller than smallest so far
        if (r < n && arr[r] < arr[smallest])
        {
            smallest = r;
        }

        // If smallest is not root
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, smallest);
        }
    }

    void heapSort(vector<int> &arr)
    {
        int n = arr.size();

        // Build min heap
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify(arr, n, i);
        }

        // Extract elements
        for (int i = n - 1; i >= 0; --i)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void printArray(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Using Priority Queue (TC: O(n log n))
class Solution2
{
public:
    vector<int> sortArrayInDescendingOrder(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr)
        {
            minHeap.push(num);
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            int top = minHeap.top();
            minHeap.pop();
            result.insert(result.begin(), top);
        }
        return result;
    }

    void printArray(vector<int> &arr)
    {
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr1 = {4, 6, 3, 2, 9};
    vector<int> arr2 = {4, 6, 3, 2, 9};

    Solution1 obj1;
    Solution2 obj2;

    obj1.heapSort(arr1);
    obj1.printArray(arr1);

    vector<int> sortedArr2 = obj2.sortArrayInDescendingOrder(arr2);
    obj2.printArray(sortedArr2);

    return 0;
}