#include <iostream>
#include <stack>
using namespace std;

// helper function to insert at bottom
void solve(stack<int> &s, int x) {
    if (s.empty()) { // base case
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, x); // recursive call

    s.push(num); // restore elements
}

// main function
stack<int> pushAtBottom(stack<int> &myStack, int x) {
    solve(myStack, x);
    return myStack;
}

int main() {
    stack<int> st;
    int n, x;

    cout << "Enter stack size: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }

    cout << "Enter element to push at bottom: ";
    cin >> x;

    pushAtBottom(st, x);

    cout << "Stack after pushing at bottom: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
