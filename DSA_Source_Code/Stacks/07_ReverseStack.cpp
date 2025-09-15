#include <iostream>
#include <stack>
using namespace std;

// helper: insert element at bottom
void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();

    insertAtBottom(s, element); // recursive call

    s.push(num); // restore elements
}

// reverse stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) return; // base case

    int num = st.top();
    st.pop();

    reverseStack(st);       // recursive call
    insertAtBottom(st, num);
}

int main() {
    stack<int> st;
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    reverseStack(st);

    cout << "Reversed stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}