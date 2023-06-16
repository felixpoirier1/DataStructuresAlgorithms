#include<iostream>
using namespace std;

void double_values(int * arr, int length){
    for(int i=0; i < length; i++){
        *(arr + i) *= 2; 
    }
}

int main(){

    int len = 5;
    int * arr = new int[len];

    //allocating values to an array of pointers
    for(int i=0; i < len; i++){
        *(arr + i) = i;
    }

    //multiplying each element by 2
    double_values(arr, len);

    //printing these values
    for(int i=0; i < len; i++){
            cout << *(arr + i) << "\t";
    }

    //deleting the array that arr is pointing
    delete [] arr;

    //interestingly arr's value (address) still exists in the stack
    cout << endl << arr << endl;

    return 0;
}