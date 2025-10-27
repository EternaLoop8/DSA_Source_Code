#include <iostream>
#include <vector>
using namespace std;

// Check if books can be allocated such that no student gets more than 'mid' pages
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

// Binary search to find the minimum possible maximum pages any student has to read
int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    if (m > n) {
        cout << "Not enough books for each student!" << endl;
        return 0;
    }

    int result = allocateBooks(arr, n, m);
    cout << "Minimum number of pages each student has to read: " << result << endl;

    return 0;
}
