// Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node
{
public:
    int data;   // stores data
    Node *prev; // pointer to previous node
    Node *next; // pointer to next node

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor (frees only this node)
    ~Node()
    {
        int value = this->data;
        cout << "Memory freed for node with data " << value << endl;
    }
};

// Traversing a linked list (Forward direction)
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get length of a linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert a node at the HEAD
void insertAtHead(Node *&tail, Node *&head, int d)
{
    if (head == NULL)
    { // empty list
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head; // new node points to old head
        head->prev = temp; // old head points back
        head = temp;       // update head
    }
}

// Insert a node at the TAIL
void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    { // empty list
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp; // update tail
    }
}

// Insert at a given POSITION
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    { // insert at end
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Delete node at a given POSITION
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
        return; // empty list safety

    if (position == 1)
    { // deleting first node
        Node *temp = head;
        head = temp->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL; // if list becomes empty
        }
        delete temp;
    }
    else
    {
        Node *curr = head;
        int cnt = 1;
        while (cnt < position && curr != NULL)
        {
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
            return; // invalid position

        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        else
        {
            tail = curr->prev; // update tail if deleting last node
        }

        if (curr->prev != NULL)
        {
            curr->prev->next = curr->next;
        }

        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    cout << "Initially empty list: ";
    print(head);
    cout << "Length: " << getLength(head) << endl;

    // Insert at head
    insertAtHead(tail, head, 11);
    insertAtHead(tail, head, 13);
    insertAtHead(tail, head, 8);
    cout << "After inserting at head: ";
    print(head);

    // Insert at tail
    insertAtTail(tail, head, 25);
    cout << "After inserting at tail: ";
    print(head);

    // Insert at position
    insertAtPosition(tail, head, 2, 100);
    insertAtPosition(tail, head, 1, 101);
    insertAtPosition(tail, head, 7, 102);
    cout << "After inserting at specific positions: ";
    print(head);

    // Delete a node
    deleteNode(7, head, tail);
    cout << "After deleting 7th node: ";
    print(head);

    if (head)
        cout << "Final Head: " << head->data << endl;
    if (tail)
        cout << "Final Tail: " << tail->data << endl;

    return 0;
}