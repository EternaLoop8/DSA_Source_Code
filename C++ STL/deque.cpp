#include <bits/stdc++.h>
using namespace std;

void printD(deque<int>& dq) {
    for (auto x: dq) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    
    // Creating an empty deque
    deque<int> dq1;

    // Creating a deque with default size and value
    deque<int> dq2(3, 4);
    
    // Creating a deque from an initializer list
    deque<int> dq3 = {1, 4, 2, 3, 5};
    
    printD(dq1);
    printD(dq2);
    printD(dq3);
    return 0;
}