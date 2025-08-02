#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a third array
void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0, j = 0, k = 0;

    // Compare elements of both arrays and insert the smaller one
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}

// Function to print the elements of an array
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int sizeofi;
    cout << "Enter the size of the first array: ";
    cin >> sizeofi;

    int arr1[100];
    cout << "Enter the elements of the first array:" << endl;
    for (int i = 0; i < sizeofi; i++) {
        cin >> arr1[i];
    }

    int sizeofj;
    cout << "Enter the size of the second array: ";
    cin >> sizeofj;

    int arr2[100];
    cout << "Enter the elements of the second array:" << endl;
    for (int j = 0; j < sizeofj; j++) {
        cin >> arr2[j];
    }

    // Declare third array to store the merged result
    int arr3[200]; // Max 100 + 100

    // Merge the arrays
    merge(arr1, sizeofi, arr2, sizeofj, arr3);

    // Print the merged array
    cout << "Merged array: ";
    print(arr3, sizeofi + sizeofj);

    return 0;
}
