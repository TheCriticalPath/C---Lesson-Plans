#include <iostream>
#include <type_traits>
#include "math.h"

// This allows us to not used the STD:: prefix on some functions
using namespace std;

int main(){
    int input = 0;
    cout << "Enter a number: ";
    cin >> input;
    double root = sqrt((double)input);
    if (trunc(root) == root){
        cout << input << " is a perfect square" << endl; 
    }else{
        cout << input << " is not perfect square" << endl;
    }
}