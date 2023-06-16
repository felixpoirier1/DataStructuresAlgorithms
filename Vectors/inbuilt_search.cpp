#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool is_half(int i, int j){
    return i/2 == j;
}
int main(){

    vector<int> arr = {10, 11, 2, 3, 4, 5, 6, 7, 8, 8, 10};

    int key = 11;

    //the find function (from <algorithm>) uses linear search, from one address, to another
    //and searches for a value
    //arr.begin() is the first address of the vector, arr.end() is the last
    vector<int>::iterator it = find(arr.begin(), arr.end(), key);

    //it is the address where the value "key" was found, subtracting the resulting address
    //by the starting address gives us an index
    if(it==arr.end())
        cout << "Element not found"<<endl;
    else
        cout << it - arr.begin() << endl;
    

    int subarray[] = {2, 3, 4};

    //search finds the starting index of a subarray inside a larger array,
    it = search(arr.begin(), arr.end(), subarray, subarray+3);

    if(it==arr.end())
        cout << "Element not found"<<endl;
    else
        cout << it - arr.begin() << endl;

    
    int half_subarray[] = {4, 4, 5};

    //search finds the starting index of a subarray inside a larger array, using
    //is_half, which will return true if (array[i]/2 == subarray[j])
    //
    it = search(arr.begin(), arr.end(), half_subarray, half_subarray+3, is_half);

    if(it==arr.end())
        cout << "Element not found"<<endl;
    else
        cout << it - arr.begin() << endl;



    /* ITERATORS ON SORTED ARRAYS */

    //binary_search returns true if it finds a number inside an array, with
    //time complexity log O(n) !!! the array must be sorted !!!
    // ==> https://en.cppreference.com/w/cpp/algorithm/binary_search
    arr = {1, 2, 5, 7, 9, 11, 12, 14, 15};
    key = 11;
    if(binary_search(arr.begin(), arr.end(), key))
        cout << key << " found in array" << endl;
    else
        cout << "Value not found"<<endl;
    

    //lower_bound finds the first element that does not satisfy (array[i] < value) 
    //in log O(n) !!! the array must be sorted !!!
    // ==> https://en.cppreference.com/w/cpp/algorithm/lower_bound

    //will return first element that is larger or EQUAL to 11
    arr = {1, 2, 5, 7, 9, 11, 11, 12, 14, 15};
    it = lower_bound(arr.begin(), arr.end(), 11);

    if(it==arr.end())
        cout << "Element not found"<<endl;
    else
        cout << arr[it - arr.begin()] << " at idex " << it - arr.begin()
        << " is the lower bound of " << "11" << endl;

    //upper finds the first element that does satisfy (value < array[i]) 
    //in log O(n) !!! the array must be sorted !!!
    // ==> https://en.cppreference.com/w/cpp/algorithm/upper_bound

    //will return first element that is larger than 11
    it = upper_bound(arr.begin(), arr.end(), 11);

    if(it==arr.end())
        cout << "Element not found"<<endl;
    else
        cout << arr[it - arr.begin()] << " at idex " << it - arr.begin()
        << " is the upper bound of " << "11" << endl;


    return 0;    

}