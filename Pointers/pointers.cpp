#include<iostream>
using namespace std;

int main(){

    int x = 0;

    int *xptr = &x;

    cout << &xptr << " points to " << xptr 
        << " which contains the value " << *xptr << endl;

    //pointer of a pointer
    int ** xxptr = &xptr;

    cout << xxptr << " ==> " << *xxptr << " ==> " << **xxptr << endl;

    //link y and x (reference variable)
    int &y = x;

    //x=0 ==> x=1
    x++;

    cout << x << " = " << y << endl;

    return 0;
}