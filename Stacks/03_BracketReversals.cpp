#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
    // if length is odd → cannot balance
    if (str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;
    for (char ch : str) {
        if (ch == '{') {
            s.push(ch);
        } else {
            // ch == '}'
            if (!s.empty() && s.top() == '{') {
                s.pop(); // valid pair
            } else {
                s.push(ch); // unmatched '}'
            }
        }
    }

    // count remaining invalid brackets
    int open = 0, close = 0;
    while (!s.empty()) {
        if (s.top() == '{') open++;
        else close++;
        s.pop();
    }

    // (open+1)/2 converts pairs of '{' into flips, same for '}'
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    string str;
    cout << "Enter a string of braces: ";
    cin >> str;

    int result = findMinimumCost(str);

    if (result == -1)
        cout << "Not possible to balance." << endl;
    else
        cout << "Minimum reversals needed = " << result << endl;

    return 0;
}
