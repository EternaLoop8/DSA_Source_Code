// Circular Linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // Freeing only this node (not entire chain)
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

/// Insert a node after a given element
void insertNode(Node *&tail, int element, int d)
{
    // Empty list case
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode; // Circular link to itself
    }
    else
    {
        // Non-empty list
        // Find the node with value == element
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
            if (curr == tail)
            {
                cout << "Element " << element << " not found in list\n";
                return;
            }
        }

        // Insert after curr
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

/// Print the circular linked list
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

/// Delete a node by value
void deleteNode(Node *&tail, int value)
{
    // Empty list
    if (tail == NULL)
    {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    // Find node to delete
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;

        if (curr == tail->next)
        { // full loop completed
            cout << "Value " << value << " not found in list\n";
            return;
        }
    }

    prev->next = curr->next;

    // Single node list
    if (curr == prev)
    {
        tail = NULL;
    }
    // If deleting tail, update tail
    else if (tail == curr)
    {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

/// Check if the list is circular
bool isCircularList(Node *head)
{
    // Empty list is circular by definition
    if (head == NULL)
        return true;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    return (temp == head);
}

/// Detect a loop in a general linked list (not just circular)
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true; // loop found
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *tail = NULL;

    // Create circular linked list by inserting nodes
    insertNode(tail, 5, 3); // inserting into empty list -> element ignored
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    // Deleting nodes
    deleteNode(tail, 5);
    print(tail);

    // Check if circular
    if (isCircularList(tail))
    {
        cout << "Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular" << endl;
    }

    return 0;
}
