#include<iostream>
#include<string>
using namespace std;

/*
Example:

We receive a path using cardinal points:

Input:
    SNNNEWE

Output:
    NNE

*/

int main(){

    int north = {0};
    int east = {0};

    char input[100];

    cin.getline(input, 100);

    for(unsigned int i = 0 ; input[i] != '\0' ; i++){
        switch(input[i]){
            case 'N': case 'n': north++;
                break;
            
            case 'S': case 's': north--;
                break;
            
            case 'E': case 'e': east++;
                break;
            
            case 'W': case 'w': east--;
                break;

        }
    }

    string vert = (north>0) ? string(north, 'N') : string(-north, 'S');
    string horz = (east>0) ? string(east, 'E') : string(-east,'W');

    cout << vert << horz << endl;

    return 0;
}