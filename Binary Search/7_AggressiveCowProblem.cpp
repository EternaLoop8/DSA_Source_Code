#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if cows can be placed with at least 'mid' distance apart
bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

// Binary search to find the largest minimum distance
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 0;
    int e = stalls[n - 1];
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter positions of stalls: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << "Enter number of cows: ";
    cin >> k;

    int result = aggressiveCows(stalls, k);
    cout << "Maximum minimum distance between cows: " << result << endl;

    return 0;
}
