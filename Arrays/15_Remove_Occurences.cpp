#include <iostream>
#include <string>
using namespace std;

// Function to remove all occurrences of 'part' from string 's'
string removeOccurrences(string s, string part) {
    // Keep removing 'part' from 's' as long as it's found
    while (s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s, part;

    // Input the main string
    cout << "Enter the main string: ";
    cin >> s;

    // Input the substring to be removed
    cout << "Enter the substring to remove: ";
    cin >> part;

    // Call the function and print the result
    string result = removeOccurrences(s, part);
    cout << "Resulting string: " << result << endl;

    return 0;
}
