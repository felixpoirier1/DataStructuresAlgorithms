#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
T sum(const vector<T>& array){
    T sum = 0;
    for(auto i: array){
        sum += i;
    }
    return sum;
}


bool bestgrade(pair<string, vector<int>>& s1, pair<string, vector<int>>& s2){
    int sum1 = sum<int>(s1.second);
    int sum2 = sum<int>(s2.second);

    return sum1 > sum2;
}

int main(){
    vector<pair<string, vector<int>>> student_marks = {
        {"Jack", {10, 20, 11}},
        {"Matthew", {10, 21, 3}},
        {"Jonah", {4, 5, 6}},
        {"George", {10, 13, 20}}
    };

    sort(student_marks.begin(), student_marks.end(), bestgrade);
    
    for(auto i: student_marks){
        cout << i.first << "\t has a final grade of\t " << sum<int>(i.second) <<endl;
    }
    
    return 0;
}
