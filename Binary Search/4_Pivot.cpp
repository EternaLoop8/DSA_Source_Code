#include<iostream> 
using namespace std;

// Function to find the index of the pivot (smallest element) in a rotated sorted array
int getPivot(int arr[], int n) {
    // If the array is not rotated (first element is less than or equal to last), pivot is at index 0
    if (arr[0] <= arr[n - 1]) return 0;

    int s = 0;         // start index
    int e = n - 1;     // end index

    // Binary search loop to find the pivot
    while (s < e) {
        int mid = s + (e - s) / 2;

        // If mid element is greater than or equal to the first element,
        // it means the smallest element lies on the right side
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            // Otherwise, it lies on the left side (including mid)
            e = mid;
        }
    }
    return s;
}

int main() {
    // Example array (not rotated)
    int arr[5] = {1, 3, 8, 10, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;

    return 0;
}
