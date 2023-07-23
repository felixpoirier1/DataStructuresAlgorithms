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

int sumBT(Node* root)
{
    int sum_left = 0;
    int sum_right = 0;
    // Code here
    if (root == NULL){
        return 0;
    }
    if (root->left){
        sum_left = sumBT(root->left);
    }
    if (root->right){
        sum_right = sumBT(root->right);
    }
    
    return sum_right + sum_left + root->key;
}

int main(){
    Node *n = buildTree();

    std::cout << "Here's the binary tree's sum " << sumBT(n) << std::endl;

    return 0;
}