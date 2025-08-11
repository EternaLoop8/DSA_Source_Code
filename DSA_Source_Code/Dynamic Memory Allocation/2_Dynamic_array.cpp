#include <iostream>
using namespace std;

// Calculates sum of an integer array
int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    // Dynamically allocate array
    int* arr = new int[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sum is: " << getSum(arr, n) << endl;

    delete[] arr; // free allocated memory

    return 0;
}
