#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};

// Function to find middle node
node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
node* merge(node* left, node* right) {
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    node* ans = new node(-1); // dummy node
    node* temp = ans;
    
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    // Attach remaining nodes
    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    
    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    return ans->next; // skip dummy node
}

// Merge Sort for linked list
node* mergeSort(node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Split list into two halves
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    // Recursive sort
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Merge sorted halves
    return merge(left, right);
}

// Utility function to insert at tail
void insertAtTail(node* &head, node* &tail, int d) {
    node* newNode = new node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Utility function to print list
void printList(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    node* tail = NULL;
    
    // Create unsorted linked list
    vector<int> values = {4, 2, 1, 5, 3};
    for(int v : values) {
        insertAtTail(head, tail, v);
    }
    
    cout << "Original List: ";
    printList(head);
    
    // Sort using mergeSort
    head = mergeSort(head);
    
    cout << "Sorted List: ";
    printList(head);
    
    return 0;
}