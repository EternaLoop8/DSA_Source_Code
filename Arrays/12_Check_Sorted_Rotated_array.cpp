#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted and rotated
bool isSortedAndRotated(const vector<int>& nums) {
    int cnt = 0;
    int n = nums.size();

    // Count the number of places where the current element is less than the previous one
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1])
            cnt++;
    }

    // Additional check between last and first element (for rotation)
    if (nums[n - 1] > nums[0])
        cnt++;

    // For a sorted and rotated array, there should be at most one "drop" in order
    return cnt <= 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call the function and print the result
    if (isSortedAndRotated(nums)) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is NOT sorted and rotated." << endl;
    }

    return 0;
}
