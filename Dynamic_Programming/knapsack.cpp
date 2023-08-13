#include<iostream>
#include<vector>

int recursive_knapsack(std::vector<int> weights, std::vector<int> values, int max_weight){
    if(weights.size() == 1){
        return weights[0] <= max_weight ? values[0] : 0;
    }

    int curr_weight = weights[weights.size() - 1];
    weights.pop_back();
    
    int curr_value = values[values.size() - 1];
    values.pop_back();
    
    int inc = 0, exc = 0;

    if (curr_weight <= max_weight){
        inc = recursive_knapsack(weights, values, max_weight - curr_weight) + curr_value;
    }
    exc = recursive_knapsack(weights, values, max_weight);

    return std::max(inc, exc);

}

int main(){
    std::vector<int> weights = {3, 5, 10, 6, 1, 20};
    std::vector<int> values = {5, 2, 10, 3, 4, 12};
    int max_weight = 21;

    std::cout << recursive_knapsack(weights, values, max_weight) << std::endl;
    return 0;
}