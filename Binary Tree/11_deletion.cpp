// Deletion in Binary Tree
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

// deleting the deepest node in binary tree
void deleteDeepest(Node *root, Node *dNode)
{
    queue<Node *> q;
    q.push(root);

    Node *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        // delete the current node if it is deepest node
        if (curr == dNode)
        {
            curr = NULL;
            delete (dNode);
            return;
        }

        // Check the right child first
        if (curr->right)
        {
            // delete the right child if it is the deepest node;
            if (curr->right == dNode)
            {
                curr->right = NULL;
                delete (dNode);
                return;
            }
            q.push(curr->right);
        }

        // Check the left child
        if (curr->left)
        {
            // delete the right child if it is the deepest node;
            if (curr->left == dNode)
            {
                curr->left = NULL;
                delete (dNode);
                return;
            }
            q.push(curr->left);
        }
    }
}

// Deleting the node with given key
Node *deletion(Node *root, int key)
{

    // Empty tree
    if (root == NULL)
    {
        return NULL;
    }

    // Only one node case
    if (root->left == NULL && root->right == NULL)
    {

        // If root node is the key, delete it
        if (root->data == key)
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }

    queue<Node *> q;
    q.push(root);

    Node *curr;
    Node *keyNode = NULL;

    // Level order traversal to find the deepest node and the key node
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        // If curr node is key node
        if (curr->data == key)
        {
            keyNode = curr;
        }

        if (curr->left)
        {
            q.push(curr->left);
        }

        if (curr->right)
        {
            q.push(curr->right);
        }
    }

    // If key node is found, replace its data with deepest node
    if (keyNode != NULL)
    {
        int x = curr->data;
        keyNode->data = x;
        deleteDeepest(root, curr);
    }
    return root;
}

// Inorder travrsal of a binary tree
void inorder(Node *curr)
{
    if (!curr)
    {
        return;
    }
    inorder(curr->left);
    cout << curr->data << " ";
    inorder(curr->right);
}

int main()
{

    // Construct the binary tree
    //       10
    //      /  \       
  	//    11    9
    //   / \   / \     
  	//  7  12 15  8

    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    int key = 11;
    root = deletion(root, key);

    inorder(root);
    cout << endl;
    return 0;
}
