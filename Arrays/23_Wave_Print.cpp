#include <iostream>
#include <vector>
using namespace std;

// Function to return the wave print of a 2D matrix
vector<int> wavePrint(vector<vector<int>>& arr, int nRows, int mCols) {
    vector<int> ans;

    for (int col = 0; col < mCols; col++) {
        // If column index is odd: bottom to top
        if (col % 2 != 0) {
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        // If column index is even: top to bottom
        else {
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Creating 2D vector (matrix)
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Get the wave order
    vector<int> result = wavePrint(matrix, rows, cols);

    // Print the result
    cout << "Wave Print: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
