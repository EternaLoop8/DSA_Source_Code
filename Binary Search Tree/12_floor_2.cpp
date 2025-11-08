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

int floor(Node* root, int x){

    int floorValue = -1;

    while (root != NULL) {
        if (root->data == x) {
            return root->data;
        }

        if (root->data > x) {
            root = root->left;
        }
        else {
            floorValue = root->data;
            root = root->right;
        }
    }
    return floorValue;
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