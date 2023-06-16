#include<iostream>
using namespace std;

//pass-by reference
void applyTax(int &income){
    income = income*(1-0.1);
}

void applyTax(int *income){
    *income = (*income)*(1-0.1);
}
int main(){
    int money = 1000;

    //pass-by reference : 
    //applyTax(money): money=1000 ===> money=900
    applyTax(money);
    cout << money << endl;


    int *moneyptr = &money;

    //pass-by pointer
    //applyTax(moneyptr): *moneyptr=900 ===> *moneyptr=810
    applyTax(moneyptr);


    cout << money << endl;
}