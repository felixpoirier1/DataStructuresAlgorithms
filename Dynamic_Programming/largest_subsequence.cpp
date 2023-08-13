#include <iostream>
#include<vector>
#include<algorithm>

// Given an array, find the largest increasing subsequence
// Ex: 
//      Input : {1, 2, 1, 3, 2, 4, 5}
//      Output: {1, 2, 3, 4, 5}
std::vector<int> find_largest_subsequence(std::vector<int> arr){
    int len = arr.size();
    int dp[len] = {};
    std::vector<std::vector<int>> largest_subsequence = {};

    for(int i = 0; i < len; i++){
        dp[i] = 1;
        std::vector<int> current_best = {arr[i]};
        largest_subsequence.push_back(current_best);

        for(int j = i - 1; j >= 0; j--){
            if (arr[i] >= arr[j]){
                if(dp[i] <= dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    largest_subsequence[i] = largest_subsequence[j];
                    largest_subsequence[i].push_back(arr[i]);
                }
            }
        }
    }
    std::sort(largest_subsequence.begin(), largest_subsequence.end(),[](std::vector<int> a, std::vector<int> b)
                                  {
                                      return a.size() > b.size();
                                  });

    return largest_subsequence[0];
}


int main(){

    std::vector<int> arr = {1, 2, 1, 3, 60, 35, 10, 20, 40, 431, 1243, 1, 32, 56, 34, 424, 33, 4653, 23, 100};
    for(auto elem: arr){
        std::cout << elem << "\t";
    }
    std::cout << std::endl << std::endl;
    std::vector<int> largest_subsequence = find_largest_subsequence(arr);

    for(auto elem: largest_subsequence)
        std::cout << elem << "\t";
    std::cout << std::endl;

    return 0;
}