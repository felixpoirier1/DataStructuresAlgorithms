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
    int left_height = 0;
    int right_height = 0;
    if (root->right != NULL){
        right_height = height(root->right);
    }
    if (root->left != NULL){
        left_height = height(root->left);
    }

    int current_diameter = right_height + left_height;

    int largest_diameter = max(current_diameter, treeDiameter(root->right));
    largest_diameter = max(largest_diameter, treeDiameter(root->left));
    return largest_diameter;

}

int main(){
    Node *n = buildTree();

    std::cout << "Here's the binary tree's diameter " << treeDiameter(n) << std::endl;

    return 0;
}