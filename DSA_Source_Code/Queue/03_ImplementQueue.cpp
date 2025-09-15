#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear; 
    int size;

public:
    Queue() {
        size = 100001; // maximum capacity
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (qfront == rear);
    }

    // Add element to rear
    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    // Remove element from front
    int dequeue() {
        if(qfront == rear) {
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1; // optional
            qfront++;
            if(qfront == rear) { // reset indices when queue becomes empty
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // Get front element
    int frontElement() {
        if(qfront == rear) {
            return -1;
        } else {
            return arr[qfront];
        }
    }
};

// Driver code
int main() {
    Queue q;

    cout << "Enqueuing elements: 10, 20, 30\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.frontElement() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element: " << q.frontElement() << endl;

    q.enqueue(40);
    q.enqueue(50);

    while(!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    // Attempt to dequeue from empty queue
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}