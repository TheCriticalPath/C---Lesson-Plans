#include <iostream>
#include <string>
#include <stdlib.h>

// This compiler will put in a 'Q' everywhere that you use the CHAR_EXIT.
#define CHAR_EXIT '3'

using namespace std;

//Function Prototypes
char printMenu();
bool isValidChoice(char);
void generateFibonacciNumbers();
void generatePerfectNumbers(int);
void pressEnterKeyToContinue();

// Main Program
// Input: None
// Output: None
// Returns 0 when complete.
int main(){
    // Use a character variable to capture the users choice
    char chrUserChoice;
    // Use a do...while loop because we want this to run at least once.
    do{
        chrUserChoice = printMenu();
        //print a new line
        cout << endl;
        // What does the switch statement do?  
        // How else could I have written this.
        switch(chrUserChoice){
            case '1':
                generateFibonacciNumbers();
                break; // We must break here.  This exits the switch statement
            case '2':
                generatePerfectNumbers(500000);
                break; // We must break here.  This exits the switch statement
            case '3':
                //cout << "Exit!" << endl;
                break; // We must break here.  This exits the switch statement
            default:
                cout << "I wasn't expecting a " << chrUserChoice << endl;
                break; // We must break here.  This exits the switch statement
        }// End of switch(chrUserChoice)

    }while(chrUserChoice != '3');
    cout << "Goodbye!" << endl;
    return 0;
}

//NAME: printMenu
//Input: NONE
//Output: String representing the users choice.
//Descr:  Prints out the menu.  This routine contains the code that ensures a valid response
char printMenu(){
    // Use a boolean to track the validity of the response.
    bool blnTryAgain = false;
    // Use a character to capture the users input.
    char chrUserChoice;
    // Use a do...while loop because we want this to run at least once.
    do{
        system("clear");
        cout << "*****************************************" << endl;
        cout << " Special Number Generator" << endl;
        cout << "*****************************************" << endl;
        cout << "1) Calculate Fibonacci Numbers" << endl;
        cout << "2) Calculate Perfect Numbers" << endl;
        cout << "3) Exit Program" << endl;
        cout << "Please select and option : ";
        cin >> chrUserChoice;

        // Convert this to an uppercase character so we do not have to worry lower vs upper case.
        chrUserChoice = toupper(chrUserChoice);

        // Validate that they entered a valid option
        if (isValidChoice(chrUserChoice)){
                blnTryAgain = false;
        }else{
                blnTryAgain = true;
                cout << "Invalid Option entered";
                pressEnterKeyToContinue();

        }
    } while (blnTryAgain);    
    return chrUserChoice;
}              

//Name: isValidChoice
//Input: Character representing user's choice
//Output: True if the choice is valid.  False if the choice is invalid.
bool isValidChoice(char chrChoice){
    return ( chrChoice == '1' ||
             chrChoice == '2' ||
             chrChoice == '3');
}


void generateFibonacciNumbers(){
    int n = 1;
    int n1 = 1;
    int n2 = 2;

    printf("Fibonacci # %d is: %d\n", 1, n);
    printf("Fibonacci # %d is: %d\n", 2, n1);

    for(int lcv = 3; lcv <= 20; lcv++){
       n2 = n + n1;
       printf("Fibonacci # %d is: %d\n", lcv, n2);
       // Store N1 into N
       // Store N2 into N1
       n = n1;
       n1 = n2;
    }
    pressEnterKeyToContinue();
}

void pressEnterKeyToContinue(){
    cout << endl << "Press ENTER key to continue . . . " << endl;
    cin.ignore();
    cin.get();
}

void generatePerfectNumbers(int limit){
    int sum = 0;
    //Start at 4.  1,2,3 are prime
    printf("Here are all the perfect numbers less than %d\n", limit);
    for(int lcv = 4; lcv<=limit;lcv++){
        sum = 0;
        //          cout << lcv << ":";

        for (int i = 1; i <= lcv/2; i++){
            if(lcv % i == 0)
            {
            //    cout << i << ",";
                sum += i;
            }
        }
       // cout << endl;
        if (sum == lcv){
            cout << sum << endl;
        }
    }
    pressEnterKeyToContinue();
}