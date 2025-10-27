// Insertion in a Binary Tree in order of level
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

Node *InsertNode(Node *root, int data)
{
    // If tree is already NULL
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // level order traversal until find a node pointing to NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // Check for left if null then innsert right, then move to right
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        else
        {
            curr->left = new Node(data);
            return root;
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
        else
        {
            curr->right = new Node(data);
            return root;
        }
    }
    return root;
}

// Inorder traversal of a binary tree
void inorder(Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    inorder(curr->left);
    cout << curr->data << ' ';
    inorder(curr->right);
}
int main()
{

    // Constructing the binary tree
    //          10
    //        /    \ 
    //       11     9
    //      /      / \
    //     7      15   8

    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    int key = 12;
    root = InsertNode(root, key);

    // After insertion 12 in binary tree
    //          10
    //        /    \ 
    //       11     9
    //      /  \   / \
    //     7   12 15  8

    inorder(root);
    cout << endl;

    return 0;
}