#include<iostream>
using namespace std;

// Function to print the size and elements of the array
void print(int arr[], int n) {
    cout << "Size of array is " << n << endl;

    // Print all elements in the array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
}

// Recursive function for Linear Search
bool linearSearch(int arr[], int size, int k) {
    // Debug print to see the current state of the array
    print(arr, size);

    // Base Case 1: if size becomes 0, element is not found
    if(size == 0) 
        return false;

    // Base Case 2: if the first element matches the key, return true
    if(arr[0] == k) {
        return true;
    }
    else {
        // Recursive Case:
        // Move to the next element (arr + 1)
        // Reduce size by 1 and search again
        bool remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
    }
}

int main() {
    int arr[5] = {3, 5, 1, 2, 6};
    int size = 5;                  
    int key = 6;                    

    // Call linear search function
    bool ans = linearSearch(arr, size, key);

    // Output the result
    if(ans) {
        cout << "Present" << endl;
    }
    else {
        cout << "Absent" << endl;
    }

    return 0;
}
