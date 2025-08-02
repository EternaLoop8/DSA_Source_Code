#include <iostream>
#include <vector>
using namespace std;

// Function to search for the target in the matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0;           // start from first row
    int j = col - 1;     // start from last column

    while (i < row && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            i++; // move down
        } else {
            j--; // move left
        }
    }

    return false;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter elements of the matrix row-wise:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Element found in the matrix.\n";
    } else {
        cout << "Element not found in the matrix.\n";
    }

    return 0;
}
