#include <iostream>
#include <vector>
using namespace std;

// Function to find intersection of two sorted arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr1(n);
    cout << "Enter " << n << " elements of first (sorted) array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> arr2(m);
    cout << "Enter " << m << " elements of second (sorted) array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = findArrayIntersection(arr1, n, arr2, m);

    cout << "Intersection elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
