#include <iostream>
using namespace std;

class kQueue {
public:
    int n;        // total size of array
    int k;        // number of queues
    int *front;   // front indices of k queues
    int *rear;    // rear indices of k queues
    int *arr;     // actual array to store elements
    int freeSpot; // first free index in arr
    int *next;    // next free or next element indices

public:
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // last index

        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn) {
        // Overflow check
        if (freeSpot == -1) {
            cout << "No Empty space is present" << endl;
            return;
        }

        int index = freeSpot;       // get first free index
        freeSpot = next[index];     // update freeSpot

        // If first element in queue
        if (front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            next[rear[qn - 1]] = index; // link new element
        }

        next[index] = -1;           // update next
        rear[qn - 1] = index;       // update rear
        arr[index] = data;          // insert element
    }

    int dequeue(int qn) {
        // Underflow check
        if (front[qn - 1] == -1) {
            cout << "Queue UnderFlow" << endl;
            return -1;
        }

        int index = front[qn - 1];        // index to remove
        front[qn - 1] = next[index];      // move front forward
        next[index] = freeSpot;           // add index to free list
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    kQueue q(10, 3); // 10 total slots, 3 queues

    // Enqueue elements
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    // Dequeue elements
    cout << q.dequeue(1) << endl; // 10
    cout << q.dequeue(2) << endl; // 20
    cout << q.dequeue(1) << endl; // 15
    cout << q.dequeue(1) << endl; // 25

    // Dequeue from empty queue
    cout << q.dequeue(1) << endl; // Underflow, -1

    return 0;
}