#include <iostream>
#include <vector>
using namespace std;

// Function to return the spiral order of a matrix
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    int startingRow = 0, startingCol = 0;
    int endingRow = row - 1, endingCol = col - 1;

    while (count < total) {
        // Top row
        for (int i = startingCol; count < total && i <= endingCol; i++) {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Right column
        for (int i = startingRow; count < total && i <= endingRow; i++) {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Bottom row
        for (int i = endingCol; count < total && i >= startingCol; i--) {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // Left column
        for (int i = endingRow; count < total && i >= startingRow; i--) {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements row-wise:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
