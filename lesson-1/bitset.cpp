#include <string>
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int input = 0;

    std::cout << "Enter a number to display as binary: " << std::endl;
    std::cin >> input;

    // Convert the input to a bit array
    std::bitset<16> b(input);
    std::cout << input << " in binary is " << b << std::endl;
}
