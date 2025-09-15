#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Example of modulo operation
    cout << "(-1) % 1 = " << (-1) % 1 << endl;

    // --------- Using deque ---------
    deque<int> d;

    d.push_front(12); // insert at front
    d.push_back(14);  // insert at back

    cout << "Front of deque: " << d.front() << endl; // 12
    cout << "Back of deque: " << d.back() << endl;   // 14

    d.pop_front(); // remove front
    cout << "After pop_front, front: " << d.front() << ", back: " << d.back() << endl;

    d.pop_back(); // remove back
    if(d.empty())
        cout << "Deque is empty" << endl;
    else
        cout << "Deque is not empty" << endl;

    // --------- Using queue ---------
    queue<int> q;

    q.push(11);
    q.push(15);
    q.push(13);

    cout << "Front of queue: " << q.front() << endl; // 11
    cout << "Size of queue: " << q.size() << endl;   // 3

    q.pop();
    q.pop();
    q.pop();

    cout << "Size of queue after pops: " << q.size() << endl; // 0
    if(q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    return 0;
}