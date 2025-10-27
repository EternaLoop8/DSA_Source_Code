#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to reverse a vector of characters
void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        swap(s[start++], s[end--]);
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Convert string to vector<char>
    vector<char> s(input.begin(), input.end());

    // Call the reverse function
    reverseString(s);

    // Print the reversed string
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
