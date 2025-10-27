#include <iostream>
#include <climits>
using namespace std;

// Function to find the index of the row with the largest sum
int largestRowSum(int arr[][3], int row, int col) {
    int maxSum = INT_MIN;
    int rowIndex = -1;

    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }

        if(sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum row sum is: " << maxSum << endl;
    return rowIndex;
}

int main() {
    // Define a 3x3 2D array (static size)
    int arr[3][3];

    // Input elements into the array
    cout << "Enter 9 elements for a 3x3 matrix:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // Output the 2D array
    cout << "\nThe 3x3 matrix is:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Find and print the index of the row with the largest sum
    int maxRow = largestRowSum(arr, 3, 3);
    cout << "Row with the maximum sum is at index: " << maxRow << endl;

    return 0;
}
