// Recursive Approach
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

int floor(Node* root, int x){

    if (root == NULL){
        return -1;
    }

    if (root->data == x) {
        return root->data;
    }

    if (root->data > x) {
        return floor(root->left, x);
    }

    int floorValue = floor(root->right, x);

    return (floorValue <= x && floorValue != -1) ? floorValue : root->data;
}

int main() {
  
    // Representation of the given tree
    //       10
    //       / \
    //      5  15
    //         / \
    //        12 30 
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int x = 14;
    cout << floor(root, x) << endl;
    return 0;
}