#include <bits/stdc++.h>
using namespace std;

// Function to reverse a vector
vector<int> reverse(vector<int> v) {
    int s = 0;
    int e = v.size() - 1;

    // Swap elements from both ends
    while (s < e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

// Function to add two arrays representing numbers
vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    // Step 1: Add corresponding digits from both arrays
    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
        j--;
    }

    // Step 2: If first array still has digits
    while (i >= 0) {
        int sum = a[i] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
    }

    // Step 3: If second array still has digits
    while (j >= 0) {
        int sum = b[j] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        j--;
    }

    // Step 4: If there is still a carry left
    while (carry != 0) {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    // The result is in reverse order
    return reverse(ans);
}

// Function to take a number as a string and store digits in a vector
vector<int> inputNumber(int size) {
    vector<int> num(size);
    for (int i = 0; i < size; i++) {
        cin >> num[i]; // Input digits one by one
    }
    return num;
}

// Function to print a vector
void printVector(const vector<int>& v) {
    for (int digit : v) {
        cout << digit << " ";
    }
    cout << endl;
}

int main() {
    int n, m;

    cout << "Enter the number of digits in the first number: ";
    cin >> n;
    cout << "Enter digits of the first number (one by one): ";
    vector<int> number1 = inputNumber(n);

    cout << "Enter the number of digits in the second number: ";
    cin >> m;
    cout << "Enter digits of the second number (one by one): ";
    vector<int> number2 = inputNumber(m);

    // Calculate the sum
    vector<int> result = findArraySum(number1, n, number2, m);

    cout << "Result of the addition is: ";
    printVector(result);

    return 0;
}
