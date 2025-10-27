#include <iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // constructor
    TwoStack(int s) {
        size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // push in stack 1
    void push1(int num) {
        if (top2 - top1 > 1) {
            arr[++top1] = num;
        } else {
            cout << "Stack Overflow (Stack1)" << endl;
        }
    }

    // push in stack 2
    void push2(int num) {
        if (top2 - top1 > 1) {
            arr[--top2] = num;
        } else {
            cout << "Stack Overflow (Stack2)" << endl;
        }
    }

    // pop from stack 1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow (Stack1)" << endl;
            return -1;
        }
    }

    // pop from stack 2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow (Stack2)" << endl;
            return -1;
        }
    }
};