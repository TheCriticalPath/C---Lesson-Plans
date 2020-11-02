#include <iostream>

//simplify so we don't have to use std::
using namespace std;

int main(){         // c   r
    char arrCharacters[10];
/*
    int a = 5;
    int* b = &a;

    a = 10;

    cout << a << ":" << b << endl;
*/

    //lcv means loop control variable
    for(int lcv = 0; lcv <= 10; lcv++){
        arrCharacters[lcv] = 'A';
    }
    cout << arrCharacters << endl;

}