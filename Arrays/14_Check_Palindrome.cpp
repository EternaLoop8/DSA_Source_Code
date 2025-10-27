#include <iostream>
using namespace std;

// Function to convert a character to lowercase
char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

// Function to check if a word is a palindrome (case-insensitive)
bool checkPalindrome(char word[], int length) {
    int start = 0;
    int end = length - 1;

    while (start <= end) {
        if (toLowerCase(word[start]) != toLowerCase(word[end])) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

// Function to calculate length of the C-style string
int getLength(char word[]) {
    int count = 0;
    while (word[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char word[100];
    cout << "Enter a word: ";
    cin >> word;

    int len = getLength(word);

    if (checkPalindrome(word, len)) {
        cout << "It is a palindrome." << endl;
    } else {
        cout << "It is NOT a palindrome." << endl;
    }

    return 0;
}
