#include <iostream>

int factorial(int n){
    if (n == 0){
        return 1;
    }
    
    return n*factorial(n-1);
}

int main(){
    int val = 13;
    std::cout << "The factorial of " << val << " is equal to " << factorial(val) << std::endl;
    return 0;
}