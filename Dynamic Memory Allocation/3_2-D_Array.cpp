#include <iostream>
using namespace std;

int main() {

    int row;
    cin >> row; // input number of rows

    int col;
    cin >> col; // input number of columns

    // Step 1: Create a 2D array dynamically (array of int* pointers)
    int** arr = new int*[row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int[col]; // allocate memory for each row
    }

    // Step 2: Take input for the 2D array
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    // Step 3: Output the 2D array
    cout << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 4: Free the allocated memory (delete each row first)
    for(int i = 0; i < row; i++) {
        delete [] arr[i];
    }
    delete [] arr; // then delete the array of pointers

    return 0;
}
