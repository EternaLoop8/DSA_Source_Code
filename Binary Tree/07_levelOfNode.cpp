// Finding the maximum depth or height of a binary tree
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

// Using Recursion
int getLevel1(Node *root, int target, int level)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == target)
    {
        return level;
    }

    int leftLevel = getLevel1(root->left, target, level + 1);
    if (leftLevel != -1)
    {
        return leftLevel;
    }

    return getLevel1(root->right, target, level + 1);
}

// By Level Order Traversal
int getLevel2(Node *root, int target)
{
    if (!root)
        return -1;

    queue<Node *> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
            {
                return level;
            }

            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }

        level++;
    }

    return -1;
}

int main()
{
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    cout << getLevel1(root, target, 1) << endl;
    cout << getLevel2(root, target) << endl;;

    return 0;
}