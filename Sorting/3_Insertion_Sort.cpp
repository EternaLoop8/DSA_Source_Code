#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        for(; j >= 0; j--) {
            if(arr[j] > temp) {
                arr[j + 1] = arr[j]; // Shift
            }
            else {
                break; // Stop if element is in correct position
            }
        }
        arr[j + 1] = temp;  // Place temp in its correct position
    } 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(n, arr);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

