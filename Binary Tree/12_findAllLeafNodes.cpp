// Finding all the leaves of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printLeafNodes(Node *root)
{

    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
    {
        printLeafNodes(root->left);
    }

    if (root->right)
    {
        printLeafNodes(root->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    printLeafNodes(root);
    return 0;
}