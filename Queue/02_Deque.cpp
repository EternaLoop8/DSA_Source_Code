#include <iostream>
using namespace std;

class Deque {	
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Push front
    bool pushFront(int x) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } 
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } 
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Push rear
    bool pushRear(int x) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } 
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        } 
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pop front
    int popFront() {
        if (isEmpty()) return -1;

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = rear = -1;
        } 
        else if (front == size - 1) {
            front = 0;
        } 
        else {
            front++;
        }
        return ans;
    }

    // Pop rear
    int popRear() {
        if (isEmpty()) return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) {
            front = rear = -1;
        } 
        else if (rear == 0) {
            rear = size - 1;
        } 
        else {
            rear--;
        }
        return ans;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Check empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)));
    }
};

// Driver code
int main() {
    Deque dq(5);

    cout << "Pushing elements at rear...\n";
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushRear(40);

    cout << "Rear element: " << dq.getRear() << endl;
    cout << "Front element: " << dq.getFront() << endl;

    cout << "Pushing element at front: 5\n";
    dq.pushFront(5);

    cout << "Now Front element: " << dq.getFront() << endl;

    cout << "Dequeuing from rear: " << dq.popRear() << endl;
    cout << "Dequeuing from front: " << dq.popFront() << endl;

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    while (!dq.isEmpty()) {
        cout << "Popped: " << dq.popFront() << endl;
    }

    cout << "Trying to pop from empty deque: " << dq.popFront() << endl;

    return 0;
}