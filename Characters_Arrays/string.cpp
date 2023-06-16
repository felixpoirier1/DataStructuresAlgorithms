#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    // your code goes here
    
    string s = {};
    char last_ch = {};
    unsigned int count = 0;
    unsigned int repetition = 1;
    
    while(count < chars.size()){
        if (chars[count] != last_ch){
            if (repetition > 1){
                s += to_string(repetition);
                repetition = 1;
            }
            s += chars[count];
        }
        else if (chars[count] == last_ch) {
            repetition++;
        }
        last_ch = chars[count];
        count++;

        if (count == chars.size() & repetition > 1){
            s += to_string(repetition);
        }
    }
    return s.length();
        
}


int main(){
    std::string s ;

    s= "Ablesaf";

    for(char ch : s){
        std::cout << s <<",";
    }
    std::cout << std::endl << std::endl; 

    vector<char> fun = {'a', 'a', 'b'};

    std::cout << compress(fun);

}