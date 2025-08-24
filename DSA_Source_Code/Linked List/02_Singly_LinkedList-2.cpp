// Inserting and Deleting nodes in Singly Linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor (frees memory recursively)
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

// Insert node at given position
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // Insert at Start
    if (position == 1)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;

        // If list was empty, tail should also update
        if (tail == NULL)
        {
            tail = temp;
        }
        return;
    }

    Node *temp = head;
    int cnt = 1;

    // Traverse to (position - 1)th node
    while (cnt < position - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at Last Position
    if (temp->next == NULL)
    {
        Node *nodeToInsert = new Node(d);
        temp->next = nodeToInsert;
        tail = nodeToInsert; // update tail
        return;
    }

    // Insert in Middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Print linked list
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete a node at given position
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    // Deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        // If only one node was present
        if (head == NULL)
        {
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        prev->next = curr->next;

        // If last node deleted, update tail
        if (curr->next == NULL)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

// Delete entire list
void deleteLinkedList(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List already empty." << endl;
        return;
    }
    delete head; // destructor cleans the chain
    head = NULL;
    tail = NULL;
    cout << "Entire linked list deleted successfully." << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Insertions
    insertAtPosition(tail, head, 1, 10);
    insertAtPosition(tail, head, 2, 20);
    insertAtPosition(tail, head, 2, 15);
    insertAtPosition(tail, head, 1, 5);
    insertAtPosition(tail, head, 5, 25);

    cout << "List after insertions: ";
    print(head);

    // Deletion
    cout << "Deleting node at position 3..." << endl;
    deleteNode(3, head, tail);
    print(head);

    cout << "Deleting entire linked list..." << endl;
    deleteLinkedList(head, tail);

    print(head); // should print "List is empty"

    return 0;
}