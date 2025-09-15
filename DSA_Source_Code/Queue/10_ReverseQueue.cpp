#include <bits/stdc++.h>
using namespace std;

// Function to reverse a queue
queue<int> rev(queue<int> q) {
    stack<int> s;

    // Step 1: Push all elements of queue into stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue (reversed order)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

// Driver code
int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    queue<int> ans = rev(q);
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}