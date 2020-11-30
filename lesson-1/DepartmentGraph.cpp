#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/**************************************************/
typedef struct strcClass{
    int intClassNumber = 0;
    int intClassSize = 0;
}strcClass;

/**************************************************/
class Department{
    #pragma region Private
    private:
        int intDepartmentNumber = 0;
        char* strDepartmentName = (char *)" ";
        strcClass classes[10];

        char classGraph[10][40];

        void initializeClassSizes(){
            for(int i = 0; i < 10; i++){
                strcClass objClass;
                objClass.intClassSize = 0;
                objClass.intClassNumber = 0;
            }
        }
    #pragma endregion
    #pragma region Public 
    public: 
        // Constructor
        Department(){
            intDepartmentNumber = 0;
            strDepartmentName = (char *)" ";
            initializeClassSizes();
        }
        // Overloaded Constructor
        Department(int number, char* name){
            intDepartmentNumber = number;
            strDepartmentName = name;
            initializeClassSizes();
        }

        void getClassGrid(char classGrid[10][40]){
            int j = 0;
            for (int i = 0; i < 10; i ++ ){
                for (j = 0; j < 40; j++){
                    classGrid[i][j] = ' ';
                }
                for (j = 0; j < classes[i].intClassSize; j++){
                    classGrid[i][j] = '*';
                }
            }            
        }

        int getNumber(){
            return intDepartmentNumber;
        }
        char* getName(){
            return strDepartmentName;
        }
        void setClassSize(int classNumber, int classSize){
            classes[classNumber].intClassNumber = classNumber;
            classes[classNumber].intClassSize = classSize;
        }
        void setNumberAndName( int departmentNumber,char* departmentName){
            strDepartmentName = departmentName;
            intDepartmentNumber = departmentNumber;
        }
        void setName(char* departmentName){
            strDepartmentName = departmentName;
        }
        void setNumber(int departmentNumber){
            intDepartmentNumber = departmentNumber;
        }
        strcClass getClass(int classNumber){
            return classes[classNumber];
        }
    #pragma endregion
};

/**************************************************/
#pragma region "Function Prototypes"
int printMenu(Department []);
void menu_collect(Department &);   
//void initializeClassSizes(int [],int);
void initializeDepartments(Department []);
void horizontal_graph(Department);
void vertical_graph(Department);
void clearScreen();
void pressEnter();
char* repeatCharacter();
#pragma endregion

#pragma region "Template Function"
template <class T>
bool isInRange(T number,T low,T high){
    return (number >= low && number <= high);
}
#pragma endregion

void pressEnter(){
    //FIX: Requires two enters after the first screen
    cout << endl;
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
    cin.get();
}

/**************************************************/
int main(){
    int intSelectedDepartment = 0;
    bool blnContinue = true;
    char chrResponse = ' ';
    do {
        Department arrDepartments[10];

        initializeDepartments(arrDepartments);
        intSelectedDepartment = printMenu(arrDepartments);
        menu_collect(arrDepartments[intSelectedDepartment]);

        horizontal_graph(arrDepartments[intSelectedDepartment]);
        vertical_graph(arrDepartments[intSelectedDepartment]);
        cout << "Enter \"Y\" to run again...";
        cin >> chrResponse;

        if (chrResponse == 'Y' || chrResponse == 'y')
            blnContinue = true;
        else
            blnContinue = false;       

    }while(blnContinue);
    return 0;
}

char* repeatCharacter(char buffer[], char chr, int count,int maxSize){
    int i = 0;
    for(i = 0; i < count; i ++){
        buffer[i] = chr;
    }

    for (int j = i; j < maxSize; j ++ ){
        buffer[j] = '\000';
    }

    return buffer;
}

void horizontal_graph(Department department){
    //system("clear");
    clearScreen();
    char buffer[40];
    cout << "Department" << repeatCharacter(buffer,' ', 30,40) << "Students\n";
    cout << endl;
    for(int i = 0; i < 10; i ++){
        strcClass objClass = department.getClass(i);
        printf("%d%02d ",department.getNumber(), objClass.intClassNumber);
        repeatCharacter(buffer, '*', objClass.intClassSize,40);
        cout << buffer;
        repeatCharacter(buffer, ' ', 40 - objClass.intClassSize,40);
        cout << buffer;
        printf(" %2d", objClass.intClassSize);
        cout << endl << endl;
    }
    pressEnter();
}



void vertical_graph(Department department){
    char chrBuffer[40];
    char* strStudentLine1 = repeatCharacter(chrBuffer,' ' ,20,40);
    char* strStudentLine2 = repeatCharacter(chrBuffer,' ' ,20,40);
    char* strDepartmentLine1 = repeatCharacter(chrBuffer,' ' ,20,40);
    char* strDepartmentLine2 = repeatCharacter(chrBuffer,' ' ,20,40);
    char* strDepartmentLine3 = repeatCharacter(chrBuffer,' ' ,20,40);
    char buffer[10];
    
    char classGrid[10][40];
    department.getClassGrid(classGrid);
    clearScreen();
    cout << "Students" << repeatCharacter(chrBuffer,' ',8,40) ;
    // Print First Digit
    for(int i = 0; i < 10; i++){
        strcClass objClass = department.getClass(i);
        snprintf(buffer, 10,"%d",objClass.intClassSize);
        // First Digit
        if (objClass.intClassSize < 10){
            strStudentLine1[i*2] = ' '; 
        }else{
            strStudentLine1[i*2] = buffer[0];
        }
        //Second Digit
        if (objClass.intClassSize < 10){
            strStudentLine2[i*2] = buffer[0];
        }else{
            strStudentLine2[i*2] = buffer[1];
        }
        strStudentLine1[i*2 + 1] = ' ';
        strStudentLine2[i*2 + 1] = ' ';

        snprintf(buffer,10,"%d%d",department.getNumber(),objClass.intClassNumber);

        strDepartmentLine1[i*2] = buffer[0];
        strDepartmentLine2[i*2] = '0';
        strDepartmentLine3[i*2] = buffer[1];
        
    }
    cout << strStudentLine1 << endl;
    cout << "                " << strStudentLine2 << endl;
    for(int i = 39; i >= 0; i--){
        cout << "                " ;
        for(int j = 0; j < 10; j++)
            cout << classGrid[j][i] << ' ';
        cout << endl;
    }
    cout << endl;
    cout << "Department      " << strDepartmentLine1 << endl;
    cout << repeatCharacter(chrBuffer,' ' ,16,40) << strDepartmentLine2 << endl;
    cout << repeatCharacter(chrBuffer,' ' ,16,40) << strDepartmentLine3 << endl;
    pressEnter();
}

void initializeDepartments(Department arrDepartments[]){
        arrDepartments[0].setNumberAndName(0,(char *)"English Department");
        arrDepartments[1].setNumberAndName(1,(char *)"Mathematics Department");
        arrDepartments[2].setNumberAndName(2,(char *)"Computer Science Department");
        arrDepartments[3].setNumberAndName(3,(char *)"Business Department");
        arrDepartments[4].setNumberAndName(4,(char *)"Kinesiology Department");
        arrDepartments[5].setNumberAndName(5,(char *)"Architecture Department");
        arrDepartments[6].setNumberAndName(6,(char *)"Biology Department");
        arrDepartments[7].setNumberAndName(7,(char *)"Education Department");
        arrDepartments[8].setNumberAndName(8,(char *)"Chemistry Department");
        arrDepartments[9].setNumberAndName(9,(char *)"Engineering Department");

}

void clearScreen(){
    for(int c = 0; c < 60; c++)
        cout << endl;
}

void initializeClassSizes(int intClassSizes[],int len){
    for(int i = 0; i < len; i++){
        intClassSizes[i] = 0;
    }
}

void menu_collect(Department& department){
    char strInput[] = " " ;
    char buffer[10];
    int intClassSize = 0;
    bool blnValidInput = false;
    bool blnAuto = true;

    clearScreen();

    srand((int) time(0));

    for(int i = 0; i < 10; i ++){
        do{
            cout << "Class sizes are from 0 - 40 Students.\n";
            printf("%d%02d ",department.getNumber(),i );
            if (blnAuto){
                snprintf(buffer,10, "%2d",(int)(random() % 40));
                intClassSize = atoi(buffer);
                printf("%d\n", intClassSize);
            }
            else{
                cin >> strInput;
                intClassSize = atoi(strInput);
            }

            blnValidInput = isInRange(intClassSize,0,40);
            if (!blnValidInput) {
                cout << "Please enter ONLY numbers 0 - 40\n";
            } 
        }while(!blnValidInput);
        department.setClassSize(i,intClassSize);
    }

    pressEnter();
}

int printMenu(Department arrDepartments[]){
    bool blnValidInput = true;
    char strInput[] = " " ;
    int intInput = 0;
    do{  
        //system("clear");  // Run the system command to clear the screen
        clearScreen();
        printf("\t\t\t\tUp Town University\n");
        cout << endl;
        for(int i = 0; i < 10; i++){
            printf("\t\t\t%2d. %s\n",arrDepartments[i].getNumber(),arrDepartments[i].getName());
        }
        cout << endl;
        if (blnValidInput==true)
            cout << "\t\t\tPlease pick the department: ";
        else
        {
            cout << "\t\t\tPlease pick a valid department: ";            
        }
        
        cin >> strInput;
        intInput = atoi(strInput);
        blnValidInput = isInRange(intInput,0,9);
    }while(!blnValidInput);
    return intInput;
}