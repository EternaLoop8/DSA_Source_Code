#include <bits/stdc++.h>
using namespace std;

// Function to find first negative integer in every window of size K
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq; // stores indices of negative numbers
    vector<long long> ans;

    // Process first window
    for (int i = 0; i < K; i++) {
        if (A[i] < 0)
            dq.push_back(i);
    }

    // Push answer for first window
    ans.push_back(!dq.empty() ? A[dq.front()] : 0);

    // Process remaining windows
    for (int i = K; i < N; i++) {
        // Remove elements which are out of current window
        if (!dq.empty() && (i - dq.front()) >= K)
            dq.pop_front();

        // Add current element if it is negative
        if (A[i] < 0)
            dq.push_back(i);

        // Append first negative for current window
        ans.push_back(!dq.empty() ? A[dq.front()] : 0);
    }

    return ans;
}

// Driver program
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}