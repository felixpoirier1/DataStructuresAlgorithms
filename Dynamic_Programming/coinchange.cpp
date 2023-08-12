 #include<cmath>
 #include<iostream>
 #include<climits>

 
 int coinchange(int m, int coins[], int l){
    int possibs[l] = {0};
    for (int i = 0; i < l; i++){
        possibs[i] = INT_MAX;
        if ((m - coins[i]) == 0){
            return 1;
        }
        else if ((m - coins[i]) > 0){
           possibs[i] = coinchange(m-coins[i], coins, l) + 1;
        }
    }
    
    int min = INT_MAX;
    for(auto i : possibs){
        min = std::min(min, i);
    }
    return min;
}



int main(){
    int m = 20;
    int coins[4] = {15, 13, 17, 11};

    std::cout << coinchange(m, coins, 4) << std::endl;
}