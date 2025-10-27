#include <iostream>
using namespace std;

void update(int **p2) {
    // *p2 changes the pointer in main, **p2 changes the value
    **p2 = **p2 + 1; 
}

void update(int *p) {
    *p = (*p) * 2; // doubles the value
}

void increment(int **p) {
    ++(**p); // increments the value
}

int main() {
    int num = 110;
    int *ptr = &num;

    increment(&ptr); // num = 111
    cout << num << endl;

    return 0;
}
