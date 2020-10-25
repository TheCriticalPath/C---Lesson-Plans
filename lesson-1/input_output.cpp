#include <iostream>
#include <limits>

int main (){

    // Use standard output to display a prompt
    std::cout << "Enter two numbers: " << std::endl;

    // Create a place to store the input;
    int v1 = 0;
    int v2 = 0;

    // Use standard input to capture
    std::cin >> v1 >> v2 ;

    // Output 
    std::cout << "The sum of " << v1 << " and " <<  v2 << " is " << v1 + v2 << std::endl;

    std::cout << std::numeric_limits<int>::min();

    return 0;
}
