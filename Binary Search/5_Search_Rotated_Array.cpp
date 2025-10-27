#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index (smallest element)
int findPivot(const vector<int>& arr) {
    int s = 0, e = arr.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }

    return s;  // Pivot index
}

// Standard binary search
int binarySearch(const vector<int>& arr, int s, int e, int key) {
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;  // Not found
}

// Main search function
int searchInRotatedArray(const vector<int>& arr, int key) {
    int n = arr.size();
    int pivot = findPivot(arr);

    if (key >= arr[pivot] && key <= arr[n - 1]) {
        // Search in right half
        return binarySearch(arr, pivot, n - 1, key);
    } else {
        // Search in left half
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = searchInRotatedArray(arr, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
