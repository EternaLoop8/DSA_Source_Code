#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse k nodes in a linked list
Node* kReverse(Node* head, int k) {
    // Base case: if list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Step 1: Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;    // Save next node
        curr->next = prev;    // Reverse link
        prev = curr;          // Move prev ahead
        curr = next;          // Move curr ahead
        count++;
    }

    // Step 2: Recursively reverse remaining nodes
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // Step 3: Return new head of reversed part
    return prev;
}

// Insert new node at the end of the list
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    for (int i = 1; i <= 6; i++) {
        insertAtTail(head, i);
    }

    cout << "Original Linked List:\n";
    printList(head);

    int k = 2;
    cout << "\nReversing in groups of " << k << "...\n";
    head = kReverse(head, k);

    cout << "Modified Linked List:\n";
    printList(head);

    return 0;
}
