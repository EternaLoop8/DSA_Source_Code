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

class Solution {
private:
    // Reverse linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Insert node at tail of a list
    void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add two reversed lists
    Node* add(Node* first, Node* second) {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0) {
            int val1 = (first != NULL) ? first->data : 0;
            int val2 = (second != NULL) ? second->data : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            if (first != NULL) first = first->next;
            if (second != NULL) second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1: reverse both input lists
        first = reverse(first);
        second = reverse(second);

        // Step 2: add them
        Node* ans = add(first, second);

        // Step 3: reverse result
        ans = reverse(ans);

        return ans;
    }
};

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // First number: 617 (6->1->7)
    Node* first = new Node(6);
    first->next = new Node(1);
    first->next->next = new Node(7);

    // Second number: 295 (2->9->5)
    Node* second = new Node(2);
    second->next = new Node(9);
    second->next->next = new Node(5);

    cout << "First Number: ";
    printList(first);
    cout << "Second Number: ";
    printList(second);

    Solution s;
    Node* result = s.addTwoLists(first, second);

    cout << "Sum: ";
    printList(result);

    return 0;
}
