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

vector<int> printKthLevel(Node* root, int k){
    // your code goes here
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int lvl = 0;
    while(lvl != k and !q.empty()){
        if (q.front() == NULL){
            ++lvl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            Node * current_node = q.front();
            q.pop();
            
            q.push(current_node->left);
            q.push(current_node->right);
        }
    }

    std::vector<int> answer;
    
    while(!q.empty()){
        if (q.front() != NULL){
            answer.push_back(q.front()->key);
        }
        q.pop();

    }

    return answer;
   
}

int main(){
    Node *n = buildTree();

    std::cout << "Which level would you like to print? ";
    int lvl;
    std::cin >> lvl;
    std::cout << std::endl;
    std::cout << "Here's the level's " << lvl << " values" << std::endl;
    std::vector<int> lvl_values = printKthLevel(n, lvl);
    for (auto v: lvl_values)
        std::cout << v << " ";

    std::cout << std::endl;
    return 0;
}