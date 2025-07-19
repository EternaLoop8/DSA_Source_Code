#include <bits/stdc++.h>
using namespace std;

// This class contains the solution to rotate an array to the right by k steps
class Solution {
public:
    // Function to rotate the array using modulus approach
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);  // Temporary array to hold rotated values

        // Place each element at its new position using modulo
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        // Copy back the rotated elements into the original array
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of positions to rotate (k): ";
    cin >> k;

    // Create an instance of Solution and call rotate()
    Solution sol;
    sol.rotate(nums, k);

    // Print the rotated array
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
