#include<bits/stdc++.h>
using namespace std;


int distance(pair<int, int> xy){
    int dist = pow(xy.first, 2) + pow(xy.second, 2) ;
    
    return dist;
}

int largestDistance(pair<int, int> xy1, pair<int, int> xy2){
    return distance(xy1) < distance(xy2);
}

vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
    // your code  goes here
    
    std::sort(v.begin(), v.end(), largestDistance);
    
    return v;
}

int main(){
    vector<pair<int, int>> vec;

    vec.push_back(pair(2, 3));
    vec.push_back(pair(1, 2));
    vec.push_back(pair(3, 4));
    vec.push_back(pair(2, 4));
    vec.push_back(pair(1, 4));

    for(auto i : vec){
        cout <<"(" << i.first << ", " << i.second << ")" << endl;
    }

    vec = sortCabs(vec);

    cout << endl << "After sorting vector :" << endl;
    for(auto i : vec){
        cout <<"(" << i.first << ", " << i.second << ")" << endl;
    }

    return 0;
}