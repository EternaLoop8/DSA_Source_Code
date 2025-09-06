#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert node at the tail of a list
void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Function to sort list of 0s, 1s and 2s
Node* sortList(Node* head) {
    // Dummy nodes for 0s, 1s, 2s lists
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // Distribute nodes into 0s, 1s and 2s lists
    while (curr != NULL) {
        int value = curr->data;
        if (value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1) {
            insertAtTail(oneTail, curr);
        }
        else {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Merge the three lists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // New head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Print function
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example list: 1->2->0->1->2->0->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}