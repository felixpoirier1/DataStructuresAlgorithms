#include<bits/stdc++.h>
using namespace std;
 
 vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    
    vector<int> r_arr;
    
    for(int col = m-1; col>=0; col--){
        if((m - col)%2 != 0){
            for(int row=0; row<n; row++)
                r_arr.push_back(arr[row][col]);
        }
        else
            for(int row=n-1; row>=0; row--)
                r_arr.push_back(arr[row][col]);
    }
    return r_arr;
}

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}


int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7}
    };

    print(WavePrint(4, 4, arr));


    return 0;
}