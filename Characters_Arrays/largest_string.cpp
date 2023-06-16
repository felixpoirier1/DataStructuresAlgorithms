#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    cin.get();

    char sentence[1000] = {};
    char largest[1000] = {};
    while(n--){
        cin.getline(sentence, 1000);

        int len = strlen(sentence);

        if (len > strlen(largest)){
            strcpy(largest, sentence);
        }
    }

    cout << largest << endl;
    return 0;
}