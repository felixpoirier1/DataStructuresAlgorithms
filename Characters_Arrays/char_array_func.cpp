#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[100] = "apple";
    char b[100];

    //length
    cout << strlen(a) << endl;

    //copy
    strcpy(b, a);
    cout << b << endl;

    //compare (0 means they are equal)
    cout << strcmp(a, b) << endl;

    char web[] = "www.";
    char domain[] = "felixpoirier.com";

    //concatenate
    cout << strcat(web, domain) << endl;
}