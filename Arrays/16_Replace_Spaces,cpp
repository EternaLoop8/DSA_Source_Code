#include <iostream>
#include <string>
using namespace std;

// Function to replace spaces with "#25"
string replaceSpaces(string &str) {
    string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            // Append each character of "#25"
            temp.push_back('#');
            temp.push_back('2');
            temp.push_back('5');
        } else {
            temp.push_back(str[i]);
        }
    }

    return temp;
}

int main() {
    string str;

    // Input the full line with spaces
    cout << "Enter a string with spaces: ";
    getline(cin, str);  // Use getline to read entire line including spaces

    // Replace spaces with "#25"
    string result = replaceSpaces(str);

    // Print the modified string
    cout << "String after replacing spaces: " << result << endl;

    return 0;
}
