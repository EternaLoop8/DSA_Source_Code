// Iterative Approach
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

int findCeil(Node* root, int key) {
    int ceil = -2;

    while (root){
        if (root->data == key) {
            return root->data;
        }
        
        if (key > root->data) {
            root = root->right;
        }

        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    for (int i = 0; i < 16; i++)
        cout << findCeil(root, i) << "\n";

    return 0;
}