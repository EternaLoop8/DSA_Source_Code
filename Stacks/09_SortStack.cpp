#include <iostream>
#include <stack>
using namespace std;

// insert element in sorted order
void sortedInsert(stack<int> &st, int num) {
    if (st.empty() || st.top() < num) { // base case
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, num); // recursive call

    st.push(n); // restore elements
}

// sort stack recursively
void sortStack(stack<int> &st) {
    if (st.empty()) return; // base case

    int num = st.top();
    st.pop();

    sortStack(st);       // recursive call
    sortedInsert(st, num);
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

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}