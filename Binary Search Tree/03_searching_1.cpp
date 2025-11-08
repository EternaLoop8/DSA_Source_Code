// Recursive
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

bool search(Node* root, int key) {

    if (root == NULL){
        return -1;
    }

    if(root->data == key){
        return 1;
    }

    if (key > root->data){
        return search(root->right, key);
    }
    else {
        return search(root->left, key);
    }
}

int main() {
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    
    // Searching for key in BST
    cout << search(root, key) << endl;
}