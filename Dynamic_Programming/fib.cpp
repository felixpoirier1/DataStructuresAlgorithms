#include <iostream>
int fib(int n, int dp[]){
    if(n == 0 or n == 1){
        return n;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);

}

int fib_bottom_up(int n){
    int a = 0;
    int b = 0;
    int count = 0;

    for(int i=0; i <= n; i++){
        if (i == 0 or i == 1){
            count = i;
        } else {
            count = a + b;
        }

        a = b;
        b = count;
    }
    return count;
}

int main(){
    int n = 20;
    int dp[n]= {};
    std::cout << fib(n, dp) << "\n"<< fib_bottom_up(n)<< std::endl;
}