#include "stdio.h"
#include <iostream>

using namespace std;

//declarations
string askQuestion(string);

int main (){
    string h = "Hello World";
    cout << h << endl;

    string response = askQuestion("What is your name? ");
    cout << "Hello " << response << endl;
}

string askQuestion(string question){
    string input = "";

    cout << question << endl;
    cin >> input;
  
    return input;

}