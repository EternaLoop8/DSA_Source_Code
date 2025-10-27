#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is alphanumeric
bool isValid(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

// Function to convert uppercase letters to lowercase
char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

// Function to check if a string is a palindrome
bool isPalindrome(string s) {
    string temp = "";

    // Remove non-alphanumeric characters and convert to lowercase
    for (char ch : s) {
        if (isValid(ch)) {
            temp.push_back(toLowerCase(ch));
        }
    }

    // Check if the processed string is a palindrome
    int start = 0, end = temp.length() - 1;
    while (start < end) {
        if (temp[start++] != temp[end--])
            return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // To allow spaces

    if (isPalindrome(input)) {
        cout << "It is a palindrome." << endl;
    } else {
        cout << "It is not a palindrome." << endl;
    }

    return 0;
}
