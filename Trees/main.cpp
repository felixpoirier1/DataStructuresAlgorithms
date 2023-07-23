#include<iostream>
#include<queue>
#include<algorithm>
// sample input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// printing pre-order : 
// 1 2 4 5 7 3 6 
// printing in-order : 
// 4 2 7 5 1 3 6 
// printing post-order : 
// 4 7 5 2 6 3 1 


class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int d){
        data = d;
        left = right = nullptr;
    }
};

Node * buildTree(){
    int d;
    std::cin >> d;

    if (d == -1){
        return NULL;
    }
    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

//sample input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
Node * buildLevelOrderTree(){
    int d;
    std::cin >> d;
    Node * root = new Node(d);
    std::queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node * current = q.front();
        q.pop();
        int c1, c2;
        std::cin >> c1 >> c2;
        if(c1 != -1){
            current->left = new Node(c1);
            q.push(current->left);
        }
        if(c2 != -1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }

    return root;
}

int height(Node * node){
    if (node == NULL){
        return 0;
    }
    return std::max(height(node->left), height(node->right)) + 1;
}

void printPreorder(Node * root){
    if (root==NULL){
        return;
    }

    std::cout << root->data << " ";

    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node * root){
    if (root == NULL){
        return;
    }
    printInorder(root->left);

    std::cout << root->data << " ";

    printInorder(root->right);
}

void printPostorder(Node * root){
    if (root == NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->data << " ";
}

void levelOrderPrint(Node * root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp = q.front();
        if (temp == NULL){
            std::cout << std::endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            q.pop();
            std::cout << temp->data << " ";
            if (temp -> left)

                q.push(temp->left);
            if (temp -> right)
                q.push(temp->right);
        }
    }
}

int main(){

    Node * n = buildLevelOrderTree();

    std::cout << "printing pre-order : " << std::endl;
    printPreorder(n);
    std::cout << std::endl;
    std::cout << "printing in-order : "<<std::endl;
    printInorder(n);
    std::cout << std::endl;
    std::cout << "printing post-order : "<<std::endl;
    printPostorder(n);
    std::cout << std::endl;
    std::cout << "printing level-order : "<<std::endl;
    levelOrderPrint(n);

    std::cout << "height of tree : "<< height(n) << std::endl;
    return 0;
}