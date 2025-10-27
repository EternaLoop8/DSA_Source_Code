#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of a key
int firstOcc(const vector<int>& arr, int n, int key) {
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1; // Go left to find earlier occurrence
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return ans;
}

// Function to find the last occurrence of a key
int lastOcc(const vector<int>& arr, int n, int key) {
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1; // Go right to find later occurrence
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return ans;
}

// Function to return both first and last positions as a pair
pair<int, int> firstAndLastPosition(const vector<int>& arr, int n, int key) {
    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5}; // Sample sorted array
    int key;
    
    cout << "Enter the element to search: ";
    cin >> key;

    pair<int, int> result = firstAndLastPosition(arr, arr.size(), key);

    if (result.first == -1) {
        cout << "Element " << key << " not found in the array." << endl;
    } else {
        cout << "First occurrence of " << key << " is at index: " << result.first << endl;
        cout << "Last occurrence of " << key << " is at index: " << result.second << endl;
    }

    return 0;
}
