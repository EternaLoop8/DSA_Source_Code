// Inserting head and tail in Singly Linked List
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
};

void printList(Node *head)
{
    Node *temp = head; // start from head
    while (temp != NULL)
    {
        cout << temp->data << " "; // print data
        temp = temp->next;         // move to next node
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{

    // Creating a new node in head position
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    // Creating a new node it the tail position
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    Node *tail = third;

    printList(head);

    insertAtHead(head, 11);

    insertAtTail(tail, 99);

    printList(head);

    return 0;
}