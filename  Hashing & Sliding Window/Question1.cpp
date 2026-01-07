// find the most frequent element in an array

#include <bits/stdc++.h>
using namespace std;

int minSubsets(int arr[], int n){

    unordered_map<int, int> freq;
    for (int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int max_count = 0, res = -1;
    for (auto i : freq) {
        if (max_count< i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
    return res;
}

int main() {
    int arr[] = {40, 50, 30, 40, 50, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSubsets(arr, n) << endl;
    
    return 0;
}