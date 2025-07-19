#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {1, 3, 2, 4, 2, 3};
    int s = 5;

    vector<vector<int>> result = pairSum(arr, s);

    for (auto pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }

    return 0;
}
