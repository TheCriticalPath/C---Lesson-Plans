#include <iostream>

using namespace std;

//declarations
string askQuestion(string);
int add(int, int);

int add(int num1, int num2){
    return num1 + num2;
}

int main (){
    string h = "Hello World";
    cout << h << endl;

    string response = askQuestion("What is your name? ");
    cout << "Hello " << response << endl;

    cout << add(93, 10) << endl;
}

string askQuestion(string question){
    string input = "";

    cout << question << endl;
    cin >> input;
    return input;

}