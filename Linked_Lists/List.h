#include<iostream>

class Node{
    public:
        int data;
        Node* next;

        Node(int data_):data(data_), next(NULL){}

        friend class List;

        ~Node(){
            if(next != NULL){
                delete next;
            }
        }
};

class List{
        Node *head;
        Node *tail;
    public:
        List(): head(NULL), tail(NULL){}
        
        Node *begin(){
            return head;
        }

        void push_front(int data){
            Node *n = new Node(data);
            if(head == NULL){
                head = tail = n;
            }
            else{
                n->next = head;
                head = n;
            }
        }

        void push_back(int data){
            Node *n = new Node(data);
            if(head==NULL){
                head = tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
        void insert(int data, int pos){
            if(pos == 0){
                push_front(data);
                return;
            }
            else{
                Node * current_node = head;
                int count = 1;
                while(current_node->next != NULL){
                    if (count == pos){
                        Node * next = current_node->next;
                        current_node->next = new Node(data);
                        current_node->next->next = next;
                        return;
                    }
                    current_node = current_node->next;
                    count++;
                }
            push_back(data);
            }
        }

        void pop_front(){

            Node * temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }

        void pop_tail(){
            Node * current_node = head;
            
            while(current_node->next != tail){
                current_node = current_node->next;
            }
            current_node->next = NULL;
            tail = current_node;
        }

        int traverse_until(int key, Node *start){
            if(start == NULL){
                return -1;
            }

            if(start->data == key){
                return 0;
            }

            int idx = traverse_until(key, start->next);
            if (idx == -1){
                return idx;
            }
            return idx + 1;
        }

        void reverse(){
            Node * current_node = head;
            Node * next = nullptr;
            Node * last = nullptr;
            
            tail = head;
            while(current_node != nullptr){
                next = current_node->next;
                current_node->next = last;
                last = current_node;

                current_node = next;
            }
            head = last;

        }

        void show(){
            Node * current_node = head;
            while(current_node->next){
                std::cout << current_node->data << " => ";
                current_node = current_node->next;
            }
            std::cout << std::endl;
        }

        ~List(){
            if(head != NULL){
                delete head;
            }
        }
};
