#include <iostream>
#include "List.h"


bool search(Node * head, int key){
    Node * temp = head;

    while(temp!= NULL){
        if (temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool recursive_search(Node * node, int key){
    if(node->data == key){
        return true;
    }
    else if (node->next == NULL){
        return false;
    }
    else{
        recursive_search(node->next, key);
    }
}

int main(){

    List linked_list;

    for (int i; i < 50; i++){
        linked_list.push_front(i);
        
    }
    
    linked_list.insert(120, 5);

    linked_list.pop_front();
    linked_list.pop_tail();

    linked_list.reverse();
    
    linked_list.show();

    std::cout << std::boolalpha;
    std::cout << "Found the value 120 ? : " << search(linked_list.begin(), 120) << "\tusing recursive search : " << recursive_search(linked_list.begin(), 120) << std::endl;
    std::cout << "Found the value 120 at the position : " << linked_list.traverse_until(120, linked_list.begin()) << std::endl;
    std::cout << "Head of the linked list contains: " << linked_list.begin()->data << std::endl;

    return 0;
}