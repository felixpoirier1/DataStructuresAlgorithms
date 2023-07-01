#include"../Linked_Lists/List.h"
#include <vector>
#include <iostream>
class Node;
class List;

template<typename T>
class ArrayStack{
    T * data;
    int n;
public:
    ArrayStack(T *data_, int n): n(n){
        data = new T[n];
        for(int i=0; i<n; i++){
            data[i] = *(data_ + i);
        }
    }

    ~ArrayStack(){
        delete[] data;
    }

    T top(){
        return data[0];
    }
};

template<typename T>
class VectorStack{
    std::vector<T> data;

public:
    VectorStack(std::vector<T> data_){
        for(int i=0; i<data_.size(); i++){
            data.push_back(data_[i]);
        }
    }

    void push(T value){
        data.insert(0, value);
    } 

    void pop(){
        data.erase(0);
    }

    T top(){
        return data.front();
    }

    void show(){
        for(T i: data)
            std::cout << i << ", ";
        
        std::cout << std::endl;
    }
};

class LinkedListStack{
    List data;

public:
    void push(int value){
        data.push_back(value);
    } 

    void pop(){
        data.pop_front();
    }

    int top(){
        return data.begin()->data;
    }

    void show(){
        data.show();
    }
};
