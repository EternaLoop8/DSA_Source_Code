// Creating a Binary Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){

    Node* firstNode = new Node(1);
    Node* secondNode = new Node (2);
    Node* thirddNode = new Node (3);
    Node* fourthNode = new Node (4);

    firstNode->left = secondNode;
    firstNode->right = thirddNode;
    secondNode->left = fourthNode;
    return 0;
}