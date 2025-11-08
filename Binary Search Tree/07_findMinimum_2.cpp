// Recursive Approach
#include<bits/stdc++.h>
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

int minValue(Node* root){

    if (root->left == NULL) return root->data;

    return minValue(root->left);
}

int main() {
    // Create BST
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

    cout << minValue(root) << endl;
}