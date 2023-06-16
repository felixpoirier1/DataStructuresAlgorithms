#include <iostream>

void printArray(int arr[], int len){

    int size = 0;

    for(size_t i=0; i<len; i++){
        size += sizeof(*(arr+i));
        std::cout << size << "\t" << *(arr+1) << std::endl;
        }

    std::cout << "In Function " << size << std::endl;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr)/sizeof(int);

    std::cout << "In Main " << sizeof(arr) << std::endl;
    printArray(arr, n);

    return 0;
}