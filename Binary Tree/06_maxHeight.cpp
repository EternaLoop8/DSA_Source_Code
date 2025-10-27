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
int height1(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int lHeight = height1(root->left);
    int rHeight = height1(root->right);

    return max(lHeight, rHeight) + 1;
}
// By Level Order Traversal
int height2(Node *root)
{
    if (!root)
        return -1;

    queue<Node *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        depth++;
    }
    return depth - 1;
}

int main()
{

    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << "Height (Recursion): " << height1(root) << endl;
    cout << "Height (Level Order): " << height2(root) << endl;

    return 0;
}