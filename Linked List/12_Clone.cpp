#include <bits/stdc++.h>
using namespace std;

// Node structure with next and arb (random) pointer
class Node {
public:
    int data;
    Node* next;
    Node* arb;

    Node(int d) {
        data = d;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
   private:
    // Function to insert a node at the end of the list
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {   // if list is empty
            head = newNode;
            tail = newNode;
        }
        else {               // otherwise append at tail
            tail -> next = newNode;
            tail = newNode;
        }
    }

   public:
    // Function to copy linked list with random (arb) pointers
    Node *copyList(Node *head)
    {
        // step 1: Create a separate clone list with same data
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: Insert clone nodes in between original nodes
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Copy random (arb) pointers
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            if(originalNode -> arb != NULL) {
                // originalNode->arb->next gives corresponding clone node
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else {
                cloneNode -> arb  = NULL;
            }
            
            // move forward
            cloneNode = cloneNode -> next;
            if(cloneNode != NULL) cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
            if(originalNode != NULL) originalNode = originalNode -> next;
        }
        
        // step 4: Separate original and clone lists (undo interleaving)
        Node* original = head;
        Node* copy = cloneHead;
        
        while (original && copy) {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }

        // step 5: Return the head of the cloned list
        return cloneHead;
    }
};

// Utility function to print list with random pointers
void printList(Node* head) {
    while(head != NULL) {
        cout << "Node: " << head->data << " ";
        if(head->arb != NULL) {
            cout << "Random: " << head->arb->data;
        } else {
            cout << "Random: NULL";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Creating original linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Assigning random (arb) pointers manually
    head->arb = head->next->next;         // 1 -> 3
    head->next->arb = head;               // 2 -> 1
    head->next->next->arb = head->next;   // 3 -> 2
    head->next->next->next->arb = NULL;   // 4 -> NULL

    cout << "Original List:\n";
    printList(head);

    Solution s;
    Node* clonedHead = s.copyList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}