#include<iostream>
#include<bitset>
using namespace std;

int main(){

    int a = 1;
    int b = 0;
    std::bitset<8> ba(a);
    std::bitset<8> bb(b);

    cout << endl << "a \t= \t1 \t= \t" << ba << endl << "b \t= \t0 \t= \t" << bb << endl << endl;

    std::bitset<8> ba_a_bb(a&b);

    cout << "Binary AND operator (finds intersection of bits equal to 1)" << endl << "a&b \t= \t" << (a&b) << " \t= \t" << ba_a_bb << endl << endl;

    std::bitset<8> ba_o_bb(a|b);

    cout << "Binary OR operator (finds union of bits equal to 1)" << endl << "a|b \t= \t" << (a|b) << " \t= \t" << ba_o_bb << endl << endl;

    std::bitset<8> by(~a);
    cout << "Binary NOT operator (inverts all values of bitset) : " << endl << "~a \t= \t-2 \t= \t" << by << endl << endl;

    std::bitset<8> bls2(a<<2);
    cout << "Binary LEFT SHIFT operator (shifts bits to the left n numbers of time, extrimity will be dropped) : " << endl << "a<<2 \t= \t" << (a<<2) << " \t= \t" << bls2 << endl << endl;


    return 0;
}