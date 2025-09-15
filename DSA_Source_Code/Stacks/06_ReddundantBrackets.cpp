#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (char ch : s) {
        // push opening bracket or operator
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } 
        else if (ch == ')') {
            bool isRedundant = true;

            // check contents inside current brackets
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // pop '('

            if (isRedundant) return true; // found redundant
        }
    }
    return false;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (findRedundantBrackets(expr))
        cout << "Redundant brackets found" << endl;
    else
        cout << "No redundant brackets" << endl;

    return 0;
}