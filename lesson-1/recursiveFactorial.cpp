#include <iostream>
// 3! = 3*2*1
int recursiveFactorial (int);

using namespace std;
// This is a single line comment
int main(){
    int myNumber = 1000;
    for(int i = 1; i < myNumber / 2; i++){
        if ( myNumber % i == 0){
            cout << i << " :factor" << endl;
        }
    }

    cout << recursiveFactorial(6) << endl;
    int result = 1;
    for(int i = 1; i <= 6; i ++){
        result = result * i;
    }
    return 0;
}

int recursiveFactorial(int i){
    int result = 1;
    if (i == 1) {
        return 1;
    }

    result = i * recursiveFactorial(i - 1);
    return result;

}


/* 
This is a 
multi-line
*/