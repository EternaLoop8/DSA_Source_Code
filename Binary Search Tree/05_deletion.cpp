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

int getHeight(Node* root, int h){
    if (root == NULL){
        return h - 1;
    }
    return max(getHeight(root->left, h + 1), getHeight(root->right, h+1));
}

void levelOrder(Node* root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    int height = getHeight(root, 0);

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        Node* node = top.first;
        int lvl = top.second;

        if (lvl > lastLevel) {
            cout << "";

            lastLevel = lvl;
        }

        // all levels are printed
        if(lvl > height) break;

        // Printing NULL Node
        cout << (node->data == -1 ? "N" : to_string(node->data)) << " ";

        //Null node has no children
        if (node->data == -1) continue;

        if (node->left == NULL){
            q.push({new Node(-1), lvl + 1});
        }
        else{
            q.push({node->left, lvl + 1});
        }

        if(node->right == NULL){
            q.push({new Node(-1), lvl + 1});
        }
        else {
            q.push({node->right, lvl + 1});
        }
    }
}

// Get inorder successor (smallest in right subtree)
Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

// Delete a node with value x from BST
Node* delNode(Node* root, int x){
    if (root == NULL){
        return root;
    }

    if (root->data > x){
        root->left = delNode(root->left, x);
    }
    else if (root->data < x){
        root->right = delNode(root->right, x);
    }
    else {
        //Node with 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //Node with 2 children
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    int x = 15;
    root = delNode(root, x);

    levelOrder(root);

    return 0;
}