#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        map<char, int> freq;   // frequency of characters
        queue<char> q;         // maintain order of characters
        string ans = "";

        for (char ch : A) {
            q.push(ch);        // add current character to queue
            freq[ch]++;        // update frequency

            // Remove all repeated characters from front
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }

            // If queue is empty, no non-repeating char
            if (q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }

        return ans;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}