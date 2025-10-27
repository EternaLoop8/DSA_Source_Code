#include <bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back to queue (reversed order)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining (n-k) elements to the back to maintain order
    int t = q.size() - k;
    while (t--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n--) {
            int a;
            cin >> a;
            q.push(a);
        }

        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}