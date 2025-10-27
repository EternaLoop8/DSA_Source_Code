// Traversing with LRN(Left subtree -> Right subtree -> Root node)
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right =  NULL;
    }
};

void postOrder(Node* node, vector<int>& res){
     if (node == NULL){
        return;
    }
    
    // Traverse to left subtree
    postOrder(node->left, res);

    // Traverse to right subtree
    postOrder(node->right, res);

    // Traversing to Root Node
    res.push_back(node->data);
}

int main() {
    // Create binary tree
    //       1
    //      /  \
    //    2     3
    //   / \     \
    //  4   5     6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    postOrder(root, res);
    
    for( int node : res) {
        cout << node << " ";
    }
    cout << endl;   

    return 0;
}