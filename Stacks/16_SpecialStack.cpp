#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;   // main stack
    int mini;       // track minimum

public:
    SpecialStack() {
        mini = INT_MAX;
    }

    // Push element with special handling for min
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                // store modified value to encode previous min
                s.push(2 * data - mini);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    // Pop element and update min if needed
    int pop() {
        if (s.empty()) return -1;

        int curr = s.top();
        s.pop();

        if (curr >= mini) {
            return curr;
        } else {
            // restore previous min
            int prevMin = mini;
            mini = 2 * mini - curr;
            return prevMin;
        }
    }

    // Get top element
    int top() {
        if (s.empty()) return -1;

        int curr = s.top();
        if (curr < mini) return mini; // encoded value
        return curr;
    }

    // Check if empty
    bool isEmpty() {
        return s.empty();
    }

    // Get current minimum
    int getMin() {
        if (s.empty()) return -1;
        return mini;
    }
};

// Driver code
int main() {
    SpecialStack st;
    st.push(5);
    st.push(2);
    st.push(10);
    st.push(1);

    cout << "Current Min: " << st.getMin() << endl; // 1
    cout << "Top: " << st.top() << endl;           // 1

    cout << "Pop: " << st.pop() << endl;           // 1
    cout << "Current Min: " << st.getMin() << endl; // 2

    cout << "Pop: " << st.pop() << endl;           // 10
    cout << "Current Min: " << st.getMin() << endl; // 2

    cout << "Pop: " << st.pop() << endl;           // 2
    cout << "Current Min: " << st.getMin() << endl; // 5

    cout << "Pop: " << st.pop() << endl;           // 5
    cout << "Is Empty: " << st.isEmpty() << endl;  // 1 (true)

    return 0;
}