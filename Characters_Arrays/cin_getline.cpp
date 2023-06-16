#include<iostream>
using namespace std;

int main(){
    char sentence[1000];


    // cin.getline() stores ostream in sentence, 
    // with a maximum length of 1000 chars where reading stops at '.'
    cin.getline(sentence, 1000, '.');

    cout << sentence << endl;

    return 0;
}