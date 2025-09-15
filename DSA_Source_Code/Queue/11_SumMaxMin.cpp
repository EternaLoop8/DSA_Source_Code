#include <iostream>
#include <deque>
using namespace std;

// Function to calculate sum of min and max of all subarrays of size k
int solve(int *arr, int n, int k) {
    deque<int> maxi(k); // Stores indices of max elements
    deque<int> mini(k); // Stores indices of min elements

    // Process first k elements
    for (int i = 0; i < k; i++) {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = arr[maxi.front()] + arr[mini.front()];

    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove elements out of the current window
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Maintain deque for max
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        // Maintain deque for min
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl; // Output: 18
    return 0;
}