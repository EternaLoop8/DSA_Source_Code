#include <iostream>
using namespace std;

// Pass-by-reference: changes the original variable
void update2(int& n) {
    n++;
}

// Pass-by-value: works on a copy, original unchanged
void update1(int n) {
    n++;
}

int main() {
    int n = 5;

    cout << "Before: " << n << endl;
    update2(n); // modifies n directly
    cout << "After: " << n << endl;

    return 0;
}
