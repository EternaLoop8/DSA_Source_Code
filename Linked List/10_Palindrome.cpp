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
    // Find middle using slow/fast pointers
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Reverse a linked list
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

public:
    // Check if list is palindrome
    bool isPalindrome(Node* head) {
        if (head->next == NULL) {
            return true;
        }

        // Step 1: find middle
        Node* middle = getMid(head);

        // Step 2: reverse second half
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while (head2 != NULL) {
            if (head2->data != head1->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: restore second half
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Example: Palindrome list 1->2->3->2->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << "List: ";
    printList(head);

    Solution s;
    if (s.isPalindrome(head))
        cout << "The list is a palindrome" << endl;
    else
        cout << "The list is not a palindrome" << endl;

    cout << "List after check (restored): ";
    printList(head);

    return 0;
}