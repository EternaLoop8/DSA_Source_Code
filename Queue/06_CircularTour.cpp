#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    // Function to find starting petrol pump index
    int tour(petrolPump p[], int n) {
        int deficit = 0; // petrol shortage so far
        int balance = 0; // current petrol balance
        int start = 0;   // starting pump index

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;

            // If balance goes negative, reset starting point
            if (balance < 0) {
                start = i + 1;
                deficit += balance; // accumulate deficit
                balance = 0;
            }
        }

        // If total petrol >= total distance, return start; else -1
        if (balance + deficit >= 0)
            return start;
        return -1;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;

        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
    return 0;
}