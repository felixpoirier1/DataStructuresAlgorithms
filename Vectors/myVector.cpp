#include <iostream>
#include "vector.h"
using namespace std;



int main(){
    Vector<int> v(2);

    cout << "Max capacity : " << v.capacity() << "\tSize : " << v.size() << endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "Max capacity : " << v.capacity() << "\tSize : " << v.size() << endl;

    for(int i=0; i<v.size();i++){
        *v[i] = ((*v[i])%2 != 0) ? 2 : *v[i];
        cout << *v[i] << endl;
    }
}