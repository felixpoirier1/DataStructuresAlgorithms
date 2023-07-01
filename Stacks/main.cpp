#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include"stack.h"

template<class T>
void insertAtBottom(std::stack<T> &s, T data){

    if (s.empty()) {
        s.push(data);
        return;
    }
    T temp = s.top();

    s.pop();

    insertAtBottom(s, data);

    s.push(temp);
}

int main(){
    int n = 3;
    int arr[n] = {1,2,3};

    //array method
    ArrayStack arr_stack(arr, 3);

    std::cout << "First element of the stack = "<< arr_stack.top()<<std::endl;

    //vector method
    std::vector<int> vect;

    for(int i=0; i<n; i++){
        vect.push_back(arr[i]);
    }
    VectorStack vector_stack(vect);

    std::cout<<vector_stack.top() << std::endl;
    vector_stack.show();

    //linked list method
    LinkedListStack link_stack{};

    for(int i=0; i<=n; i++){
        link_stack.push(arr[i]);
    }

    std::cout<<link_stack.top() << std::endl;
    link_stack.show();

    //stl method
    std::stack<std::string> books; 

    books.push("C++");
    books.push("Python");
    books.push("Machine Learning");
    books.push("Rust");
    insertAtBottom(books, std::string("fun"));

    while(!books.empty()){
        std::cout << books.top() << ", ";

        books.pop();
    }

    std::cout << std::endl;

    return 0;
}