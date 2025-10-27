#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to remove duplicates from a sorted linked list
// - Only works on sorted linked list
// - If current node and next node have same value:
//     -> delete the duplicate node
//     -> link current node to next of duplicate
// - Else just move forward

Node *uniqueSortedList(Node *head)
{
    // Empty list case
    if (head == NULL)
        return NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        // If next node exists and is duplicate
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next; // node after duplicate
            Node *nodeToDelete = curr->next;    // duplicate node
            delete nodeToDelete;                // free memory
            curr->next = next_next;             // bypass duplicate
        }
        else
        {
            curr = curr->next; // move forward if no duplicate
        }
    }
    return head;
}

// Function to print linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a sorted linked list with duplicates: 1->2->2->3->3->4->5->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    head = uniqueSortedList(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
