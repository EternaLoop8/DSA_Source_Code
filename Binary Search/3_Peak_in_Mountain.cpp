#include <iostream>
#include <vector>
using namespace std;

// Function to find peak index in a mountain array
int peakIndexInMountainArray(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;  // Move to the right part
        } else {
            end = mid;        // Move to the left part (mid could be the peak)
        }
    }

    return start; // or return end; both are same here
}

int main() {
    // Example input
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2};

    int peakIndex = peakIndexInMountainArray(mountain);

    cout << "Peak index: " << peakIndex << endl;
    cout << "Peak element: " << mountain[peakIndex] << endl;

    return 0;
}
