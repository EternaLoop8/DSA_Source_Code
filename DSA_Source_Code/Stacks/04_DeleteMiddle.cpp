#include <iostream>
#include <stack>
using namespace std;

// helper function to remove middle element
void solve(stack<int> &inputStack, int count, int size) {
    if (count == size / 2) { // base case: reached middle
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size); // recursive call

    inputStack.push(num); // push back other elements
}

// main function
void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
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

    deleteMiddle(st, n);

    cout << "Stack after deleting middle element: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}