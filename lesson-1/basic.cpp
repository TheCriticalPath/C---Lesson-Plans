#include <iostream>
#include <string.h>
using namespace std;

string passByValue(string&);
string passByPointer(string&);

// This is a single line comment
int main(){
    string strValue = "Edwin";
    string strPointer = "Jackson";

    passByValue(strValue);
    passByPointer(strPointer);

    cout << strValue << endl;
    cout << strPointer << endl;

    return 0;
}

string passByValue(string& strValue){
    strValue = "Edlose";
    return strValue;
}

string passByPointer(string& strPointer){
    strPointer = "Tiny Tony";
    return strPointer;
}

/* 
This is a 
multi-line
*/