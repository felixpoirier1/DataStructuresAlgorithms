#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 10, 12, 15};

    //adding element at the end of the vector
    arr.push_back(5);
    arr.push_back(1);

    //to remove element at the end of vector
    arr.pop_back();

    for(int i=0; i< static_cast<int>(arr.size()); i++){
        cout << arr[i] << "\t";
    }
    //length of array 
    cout << endl <<  arr.size() << endl;

    //capacity of the vector (memory allocated)
    cout << arr.capacity() << endl;

    //vector of 10 zeros
    vector<int> arr1(10, 0);

    for(int i=0; i< static_cast<int>(arr1.size()); i++){
        cout << arr1[i] << "\t";
    }


    return 0;
}

