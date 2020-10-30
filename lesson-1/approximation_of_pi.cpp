// File: approximation_of_pi.cpp
#include <iostream> // Needed for common input/output functions
#include <math.h>   // Needed for absolute value (abs) and power (pow)
#include "string.h" // Needed for the string variables


#pragma region "Macros"
#define PI 3.141592653589793
#pragma endregion

using namespace std;

#pragma region "Function Prototypes"


// Function Prototypes
// request the users input for a positive Integer
int requestPositiveInteger();

// function to calculate Leibniz series
double valueOfLeibnizSeries(double );

void printOutput(string , string );

char* addCommasToNumber(int );
#pragma endregion "Function Prototypes"

int main(){
    // Get the values for the simple approximations
    double dblPI1 = 22.0/7.0;
    double dblPI2 = 355.0/113.0;
    double dblValueOfLeibnizSeries = 0.0;
    int intUserInput = 0;
    
    // Get the users input.  The function handles the negative values.
    intUserInput = requestPositiveInteger();

    // Calculate the Leibniz Series
    dblValueOfLeibnizSeries = valueOfLeibnizSeries(intUserInput);

    printf("Sample Output for values for n at %s:\n", addCommasToNumber(intUserInput));
    cout << endl;
    printf("The value of n in the Leibniz Series:              %s\n", addCommasToNumber(intUserInput));
    printf("The Leibniz Series approximation of PI at n is:    %1.15f\n",dblValueOfLeibnizSeries);
    cout << endl;
    printf("The known value of PI to 15 decimal points:  	   %1.15f\n",PI);
    printf("The difference between PI and the Leibniz Series:  %1.15f\n",abs(PI-dblValueOfLeibnizSeries));
    cout << endl;
    printf("The approximation of PI using 22 / 7:        	   %1.15f\n",dblPI1);
    printf("The difference between PI and the Leibniz Series:  %1.15f\n",abs(dblPI1-dblValueOfLeibnizSeries));
    cout << endl;
    printf("The approximation of PI using 355 / 113:           %1.15f\n",dblPI2);
    printf("The difference between PI and the Leibniz Series:  %1.15f\n",abs(dblPI2-dblValueOfLeibnizSeries));
    cout << endl;
    
/*
The value of n in the Leibniz Series:			 1,000,000
The Leibniz Series approximation of PI at n is:	 3.141593653588775 

The known value of PI to 15 decimal points:  	 3.141592653589793
The difference between PI and the Leibniz Series: 	 0.000000999998982

The approximation of PI using 22 / 7:    	     	 3.142857142857143
The difference between PI and the Leibniz Series:	 0.001263489268368  

The approximation of PI using 355 / 113:    	 	 3.141592920353983
The difference between PI and the Leibniz Series: 	 0.000000733234792 
*/
    return 0; 
}

char* addCommasToNumber(int num){
    string output = to_string(num);
    int n = output.length() - 3;
    while(n>0){
        output.insert(n,",");
        n-=3;
    }
    return &*output.begin();
}

int requestPositiveInteger(){
    int input = 0;
    while (input <= 0){
        cout << "Please enter a positive integer that indicates the number of terms to calculate in the Leibniz series:" << endl;
        cin >> input;
        if (input <= 0){
            cout << input << " is not a positive integer.  Try Again!" << endl << endl;
        }
    }
    return input;
}

double valueOfLeibnizSeries(double nlimit){
    double pi = 0.0;
    int iteration = 0;
    while(iteration <= nlimit){
        pi += 4 * ( pow(-1,iteration) / ((2* iteration) + 1)); 
        // printf("%1.15f\n", pi);
        iteration++;
    }
    return pi;
}



