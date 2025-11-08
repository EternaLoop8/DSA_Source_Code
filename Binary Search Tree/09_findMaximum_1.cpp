// Native Approach (Inorder Traversal)
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root, vector<int> &sortedInorder){
    if (root == NULL) return;

    inorder(root->left, sortedInorder);
    sortedInorder.push_back(root->data);

    inorder(root->right, sortedInorder);
}

int maxValue(Node* root){
    if (root == NULL) return -1;

    vector<int> sortedInorder;

    inorder(root, sortedInorder);

    return sortedInorder.back();
}

int main() {
    // Representation of input binary search tree
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   /  
    //  1
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << maxValue(root) << endl;
    return 0;
}