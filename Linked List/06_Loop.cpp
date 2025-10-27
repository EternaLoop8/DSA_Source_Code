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

// Function to detect a loop using Floyd's Cycle Detection Algorithm
// - Uses slow and fast pointers
// - If they meet, a loop exists and return intersection node
// - If not, return NULL

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // move one step
        fast = fast->next->next; // move two steps

        if (slow == fast)
        {
            return slow; // loop detected
        }
    }
    return NULL; // no loop
}

// Function to find the starting node of the loop
Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    // First, check if a loop exists
    Node *intersection = floydDetectLoop(head);
    if (intersection == NULL)
        return NULL;

    // Move one pointer to head, keep the other at intersection
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow; // starting node of loop
}

// Function to remove the loop if it exists
Node *removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL)
        return head; // no loop

    // Traverse loop until we reach node before startOfLoop
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL; // break the loop
    return head;
}

   // Function to print linked list (will stop if loop is removed)

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
    // Create nodes
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop for testing (5 -> points to 3)
    head->next->next->next->next->next = head->next->next;

    // Detect loop
    if (floydDetectLoop(head) != NULL)
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    // Remove loop
    head = removeLoop(head);

    // Detect loop again
    if (floydDetectLoop(head) != NULL)
        cout << "Loop still exists" << endl;
    else
        cout << "Loop removed" << endl;

    // Print list after removing loop
    printList(head);

    return 0;
}