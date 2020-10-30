#include <iostream>
#include <limits>

int main (){

    char letterA = 'A';
    bool TorF = true;
    // Type Limits
    std::cout << "short: " << std::numeric_limits<short>::min() << " - " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "unsigned short: " << std::numeric_limits<unsigned short>::min() << " - " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "int: " << std::numeric_limits<int>::min() << " - " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "unsigned int: " << std::numeric_limits<unsigned int>::min() << " - " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "long: " << std::numeric_limits<long>::min() << " - " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "unsigned long: " << std::numeric_limits<unsigned long>::min() << " - " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "long long: " << std::numeric_limits<long long>::min() << " - " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "unsigned long long: " << std::numeric_limits<unsigned long long>::min() << " - " << std::numeric_limits<unsigned long long>::max() << std::endl;
   
    // Floating-Point 
    std::cout << "float: " << std::numeric_limits<float>::min() << " - " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "double: " << std::numeric_limits<double>::min() << " - " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "long double: " << std::numeric_limits<long double>::min() << " - " << std::numeric_limits<long double>::max() << std::endl;

    return 0;
}

