#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    // Ex : x = 0 ==> bit(x) = 00000001
    // bit(x)&1 = 
    //  00000001
    //& 00000000
    //= 00000000
    // since 00000000 == 0, then the if function won't be true
    // essentially using x&1 puts a mask on x where only the last value matters
    if (x&1){
        cout << x << " is an odd number" << endl;
    } else {
        cout << x << " is an even number" << endl;
    }

    return 0;
}