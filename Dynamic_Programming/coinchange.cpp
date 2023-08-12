 #include<cmath>
 #include<iostream>
 #include<climits>


 int td_coinchange(int m, int coins[], int l){
    int possibs[l] = {0};
    for (int i = 0; i < l; i++){
        possibs[i] = UINT16_MAX;
        if ((m - coins[i]) == 0){
            return 1;
        }
        else if ((m - coins[i]) > 0){
           possibs[i] = td_coinchange(m-coins[i], coins, l) + 1;
        }
    }
    
    int min = UINT16_MAX;
    for(auto i : possibs){
        min = std::min(min, i);
    }
    return min;
}

int bu_coinchange(int m, int coins[], int l){
    int steps[m+1] = {};

    for(int i=0; i <= m; i++){
        steps[i] = UINT16_MAX;
        for(int j=0; j < l; j++){
            if ((i - coins[j]) > 0){
                steps[i] = std::min(steps[i], steps[i-coins[j]] + 1);
            }
            else if (i == coins[j]){
                steps[i] = 1;
            }
        }
    }
    return steps[m];
}



int main(){
    int m = 4312;
    int coins[4] = {15, 13, 17, 11};

    //std::cout << td_coinchange(m, coins, 4) << std::endl;
    std::cout << bu_coinchange(m, coins, 4) << std::endl;
    
    return 0;
}