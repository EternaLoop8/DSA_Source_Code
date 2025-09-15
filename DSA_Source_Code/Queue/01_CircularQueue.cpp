#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue
    bool enqueue(int value) {
        // queue full condition
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full\n";
            return false;
        }
        else if (front == -1) { // first element
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0; // wrap-around
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeue
    int dequeue() {
        if (front == -1) { // empty
            cout << "Queue is Empty\n";
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1; // optional

        if (front == rear) { // single element
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0; // wrap-around
        }
        else {
            front++;
        }
        return ans;
    }

    // Peek front element
    int peek() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << "Front element: " << q.peek() << endl;

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    // Trying to dequeue from empty queue
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}