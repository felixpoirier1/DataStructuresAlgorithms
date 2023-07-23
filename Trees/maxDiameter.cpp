#include <bits/stdc++.h>
using namespace std;
 // sample input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
struct Node {
    int key;
    Node* left, *right;
};

Node * buildTree(){
    int d;
    std::cin >> d;

    if (d == -1){
        return NULL;
    }
    Node * n = new Node();
    n->key = d;
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int height(Node * node){
    if (node == NULL){
        return 0;
    }
    return std::max(height(node->left), height(node->right)) + 1;
}

int treeDiameter(Node * root){
    if (root == NULL){
        return 0;
    }

    int head_diameter = height(root->left) + height(root->right);
    int left_diameter = treeDiameter(root->left);
    int right_diameter = treeDiameter(root->right);
    int largest_diameter = max(head_diameter, max(left_diameter, right_diameter));
    return largest_diameter;

}

int main(){
    Node *n = buildTree();

    std::cout << "Here's the binary tree's diameter " << treeDiameter(n) << std::endl;

    return 0;
}