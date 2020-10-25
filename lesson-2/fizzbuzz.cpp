#include <iostream>
using namespace std;

int main(){
    int maxValue = 1000;
    // Start at number 1 and count up to the maximum value
    for(int lcv = 1; lcv <= maxValue; lcv++){
        // fizz is true if the lcv is evenly divisible by 3
        bool fizz = lcv % 3 == 0;
        // buzz is true if the lcv is evenly divisible by 5
        bool buzz = lcv % 5 == 0;
        if( fizz ){
            printf("Fizz"); 
        }   
        if(buzz){
            printf("Buzz");
        }
        // If fizz is not true and buzz is not true, then print the number. 
        if (!fizz && !buzz){
            printf("%d",lcv);
        }
        // print the new line.
        printf("\n");
    }
    return 0;
}
