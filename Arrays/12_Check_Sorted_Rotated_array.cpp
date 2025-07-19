#include <bits/stdc++.h>
using namespace std;

// This class contains the solution to check if the array is a rotated sorted array
class Solution {
public:
    // Function to check if the given array is sorted and rotated
    bool check(vector<int>& nums) {
        int cnt = 0;

        // Count the number of times the array is not in ascending order
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                cnt++;
        }

        // Check the rotation part: if last element is greater than first, increment count
        if (nums[nums.size() - 1] > nums[0])
            cnt++;

        // For a valid rotated sorted array, there should be at most one such "drop"
        return cnt <= 1;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    // Call the check function to see if the array is sorted and rotated
    bool result = sol.check(nums);

    // Print the result
    if (result) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is NOT sorted and rotated." << endl;
    }

    return 0;
}
