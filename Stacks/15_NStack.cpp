#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr;   // main array to store stack elements
    int *top;   // stores indexes of top elements of each stack
    int *next;  // helper array for free spots and links
    int n, s;   // n = number of stacks, s = size of array
    int freespot; // beginning index of free spots

public:
    // Constructor
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialize all stacks as empty
        for (int i = 0; i < n; i++) top[i] = -1;

        // initialize next array as linked list of free spots
        for (int i = 0; i < s; i++) next[i] = i + 1;
        next[s - 1] = -1;

        // first free spot
        freespot = 0;
    }

    // Push element into m-th stack
    bool push(int x, int m) {
        // Overflow check
        if (freespot == -1) return false;

        int index = freespot;     // take free index
        arr[index] = x;           // insert element
        freespot = next[index];   // update free spot

        next[index] = top[m - 1]; // link to previous top
        top[m - 1] = index;       // update top pointer

        return true;
    }

    // Pop element from m-th stack
    int pop(int m) {
        // Underflow check
        if (top[m - 1] == -1) return -1;

        int index = top[m - 1];    // index of top element
        top[m - 1] = next[index];  // update top to previous element

        next[index] = freespot;    // add freed index to free list
        freespot = index;

        return arr[index];
    }
};

// Driver code
int main() {
    NStack st(3, 10); // 3 stacks in an array of size 10

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);

    cout << "Pop from stack 1: " << st.pop(1) << endl; // 20
    cout << "Pop from stack 2: " << st.pop(2) << endl; // 30
    cout << "Pop from stack 3: " << st.pop(3) << endl; // 40
    cout << "Pop from stack 1: " << st.pop(1) << endl; // 10
    cout << "Pop from stack 1 (empty): " << st.pop(1) << endl; // -1

    return 0;
}