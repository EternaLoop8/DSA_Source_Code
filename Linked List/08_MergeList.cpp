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

// Helper function: insert nodes of second into first in sorted order
void solve(Node* first, Node* second) {
    Node* curr1 = first;
    Node* next1 = curr1->next;

    Node* curr2 = second;
    Node* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL) {
                curr1->next = curr2;
                return;
            }
        }
    }
}

// Main function to merge two sorted linked lists
Node* sortTwoLists(Node* first, Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        solve(first, second);
        return first;
    }
    else {
        solve(second, first);
        return second;
    }
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
    Node* first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);

    Node* second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);

    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    Node* merged = sortTwoLists(first, second);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}