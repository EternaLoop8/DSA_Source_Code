// Search a node in Binary Tree
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

bool ifNodeExists(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    // recursion on left subtree
    bool res1 = ifNodeExists(root->left, key);

    // if node found, no need to look further
    if(res1){
        return true;
    }

    // if node not found in left, recursion to right subtree
    bool res2 = ifNodeExists(root->right, key);

    return res2;
}

int main() {
   
    // Binary tree  
    //          0
    //        /  \
    //       1    2
    //      / \   / \
    //     3   4 5   6
    //    /   / \
    //   7   8   9
    Node* root = new Node(0);
    root->left = new Node(1);
    root->left->left = new Node(3);
    root->left->left->left = new Node(7);
    root->left->right = new Node(4);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int key = 4;

    if (ifNodeExists(root, key))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}