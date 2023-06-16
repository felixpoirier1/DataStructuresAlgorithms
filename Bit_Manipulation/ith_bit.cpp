#include <iostream>
#include <bitset>
using namespace std;


/**
 * @brief Get the Ith Bit object
 * 
 * @param n Integer who's ith bit is search
 * @param i Index (starting from the end)
 * @return true if ith bit is one, false otherwise
 */
bool getIthBit(int n, int i){
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}

void setIthBit(int &n, int i){
    int mask = (1<<i);
    n = (n|mask);
}

void clearIthBit(int &n, int i){
    int mask = ~(1<<i);
    n = (n&mask);
}

void updateIthBit(int &n, int i){
    (getIthBit(n,i)) ? clearIthBit(n,i) : setIthBit(n, i);
}

void clearLastIBits(int &n, int i){
    int mask = (-1<<i);
    n = (n&mask);
}

int main(){
    int n = 5;
    bitset<8> x(n);
    int i;
    cout << " Select the index bit of a number n = 5 = "<< x << " : ";
    cin >> i;
    cout << endl << "I found that the bit at index " << i << " is equal to " << getIthBit(n, i) << endl;
    cout << endl << "Would you like to change the value of that bit to " << !getIthBit(n,i) << "? (Y/N) : ";
    char y;
    cin >> y;
    if (y=='Y' or y == 'y'){
        updateIthBit(n, i);
        x = n;
        cout << "The new value is " << n << " which is equal to " << x << " in binary" << endl;
    }

    cout << "From the end, how many bits do you want to clear from " << x << endl;
    cin >> i;   
    clearLastIBits(n, i);
    x = n;
    cout <<  "The new value is " << n << " which is equal to " << x << " in binary" << endl;
    return 0;
}