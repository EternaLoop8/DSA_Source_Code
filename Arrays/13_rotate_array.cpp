#include <bits/stdc++.h>
using namespace std;

// Function to rotate the array to the right by k positions
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);  // Temporary array to hold rotated values

    // Place each element at its new rotated position using modulo
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    // Copy rotated values back to original array
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter number of positions to rotate (k): ";
    cin >> k;

    // In case k is greater than array size
    k = k % n;

    // Rotate the array
    rotateArray(nums, k);

    // Print the rotated array
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
