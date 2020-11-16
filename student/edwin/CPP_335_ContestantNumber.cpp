// Edwin Sanchez CPP_335_ContestantNumber

#include <iostream>

using namespace std;

//sets up main menu screen
void mainMenu();
//generates the fibonacci numbers
void generateFibonacciNumbers();
//generates the perfect numbers under 1000
void generatePerfectNumbers();
// pauses the screen an clears it (its supposed to)
void pause();

int main() {

    mainMenu();

}

void mainMenu() {
    //loop off switch
    bool boolTurnOff = false;

    //runs until the user tells it to stop
    do {
        cout << "******************************" << endl;
        cout << " Special Number Generator" << endl;
        cout << "******************************" << endl;
        cout << "1) Calculate Fibonacci Numbers" << endl;
        cout << "2) Calculate Special Numbers" << endl;
        cout << "3) Exit Program" << endl;
        cout << "Please select an option : ";
        int intMenuChoice = 0;
        cin >> intMenuChoice;

        //gets user input and decides which option to display or to stop the program
        if(intMenuChoice == 1) {
            cout << "" << endl;
            generateFibonacciNumbers();
            pause();
        }
        else if(intMenuChoice == 2) {
            cout << "" << endl;
            generatePerfectNumbers();
            pause();
        }
        else if(intMenuChoice == 3) {
            cout << "Goodbye!" << endl;
            boolTurnOff = true;
        }
        else {
            cout << "" << endl;
            cout << "Invalid Option entered" << endl;
            pause();
        }

        

    } while (boolTurnOff == false);
    

}

//generates fibonacci numbers up to 20
void generateFibonacciNumbers() {
    
    int intFibNum1 = 0;
    int intFibNum2 = 1;
    int intFibSum = 1;


    for(int lcv = 1; lcv <= 20; lcv++) {       

        cout << "Fibonacci # " << lcv << " is: " << intFibSum << endl;
        intFibSum = intFibNum1 + intFibNum2;
        intFibNum1 = intFibNum2;
        intFibNum2 = intFibSum;

    }

    cout << "" << endl;

}

//generates perfect numbers under 1000
void generatePerfectNumbers() {

    cout << "Here are all the perfect numbers less than 1000." << endl;

    //goes through every number from 1 to 999
    for(int lcv = 1; lcv < 1000; lcv++) {

        int intFactorAdder = 0;

        //runs through every number up to half of the current number
        for(int i = 1; i <= lcv/2; i++ ) {

        //if the current number (lcv) is divisible by i, then i is a factor. This adds all of the 'i's in the variable intFactorAdder
            if(lcv % i == 0) {
                intFactorAdder += i;
            }

        }

        //if the current number is equal all of its factors, then display the number
        if(lcv == intFactorAdder) {
            cout << lcv << endl;
        }

    }

    cout << "" << endl;

}

void pause() {

    cout << "Press any key to continue: . . . " << endl;
    getchar();
    cout << "" << endl;

}