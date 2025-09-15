#include <iostream>
#include <stack>
using namespace std;

// check if parentheses are valid
bool isValidParenthesis(string expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch); // opening bracket
        } else {
            // closing bracket
            if (!s.empty()) {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    s.pop(); // matched
                } else {
                    return false; // mismatch
                }
            } else {
                return false; // no opening for closing
            }
        }
    }
    return s.empty(); // valid if nothing left
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isValidParenthesis(expr))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}