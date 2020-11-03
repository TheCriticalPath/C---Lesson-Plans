#include <iostream>
#include <string>
#include <algorithm>

// This compiler will put in a 'Q' everywhere that you use the CHAR_EXIT.
#define CHAR_EXIT 'Q'

using namespace std;

//Function Prototypes
char printMenu();
bool isValidChoice(char);

int main(){
    // Use a character variable to capture the users choice
    char chrUserChoice;
    // Use a do...while loop because we want this to run at least once.
    do{
        chrUserChoice = printMenu();
        // What does the switch statement do?  How else could I have written this.
        switch(chrUserChoice){
            case '1':
                cout << "You chose option 1.  Good Choice!" << endl;
                break; // We must break here.  This exits the switch statement
            case '2':
                cout << "You chose option 2.  Well done!" <<endl;
                break;
            case 'Q':
                cout << "No don't leave!" << endl;
                break;
            default:
                cout << "I wasn't expecting a " << chrUserChoice << endl;
                break;
        }

    }while(chrUserChoice != CHAR_EXIT);
    cout << "Goodbye!" << endl;
    return 0;
}

//NAME: printMenu()
//Input: NONE
//Output: String representing the users choice.
char printMenu(){
    // Use a boolean to track the validity of the response.
    bool blnTryAgain = false;
    // Use a character to capture the users input.
    char chrUserChoice;
    // Use a do...while loop because we want this to run at least once.
    do{
        cout << "Please select from one of the following options:" << endl;
        cout << "1 - Option 1" << endl;
        cout << "2 - Option 2" << endl;
        cout << "Q - Quit" << endl;
        cout << " ? ";
        cin >> chrUserChoice;

        // Convert this to an uppercase character so we do not have to worry lower vs upper case.
        chrUserChoice = toupper(chrUserChoice);

        // Validate that they entered a valid option
        if (isValidChoice(chrUserChoice)){
                blnTryAgain = false;
        }else{
                blnTryAgain = true;
                printf("%c is not a valid option!  Please try again.\n",chrUserChoice);
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
             chrChoice == 'Q');
}