#include <iostream>
#include <string.h>
#include <stdlib.h>

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
        char* strDepartmentName = " ";
        strcClass classes[10];
    #pragma endregion
    #pragma region Public 
    public: 
        void initializeClassSizes(){
            for(int i = 0; i < 10; i++){
                strcClass objClass;
                objClass.intClassSize = 0;
                objClass.intClassNumber = 0;
            }
        }
        Department(){
            intDepartmentNumber = 0;
            strDepartmentName = " ";
            initializeClassSizes();
        }
        Department(int number, char* name){
            intDepartmentNumber = number;
            strDepartmentName = name;
            initializeClassSizes();
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
void initializeClassSizes(int [],int);
void initializeDepartments(Department []);
void horizontal_graph(Department);
void vertical_graph(Department);
#pragma endregion

#pragma region "Template Function"
template <class T>
bool isInRange(T number,T low,T high){
    return (number >= low && number <= high);
}
#pragma endregion

/**************************************************/
int main(){
    int intDepartment = 0;
    Department arrDepartments[10];
    initializeDepartments(arrDepartments);
    intDepartment = printMenu(arrDepartments);
    menu_collect(arrDepartments[intDepartment]);
    horizontal_graph(arrDepartments[intDepartment]);

    return 0;

}

void repeatCharacter(char chr, int count){
    for(int i = 0; i < count; i ++){
        cout << chr;
    }
}

void horizontal_graph(Department department){
    system("clear");
    cout << "Department                                Students\n";
    cout << endl;
    for(int i = 0; i < 10; i ++){
        strcClass objClass = department.getClass(i);
        printf("%d%02d ",department.getNumber(), objClass.intClassNumber);
        repeatCharacter('*', objClass.intClassSize);
        repeatCharacter(' ', 40 - objClass.intClassSize);
        printf(" %d", objClass.intClassSize);
        cout << endl << endl;
    }
}

void vertical_graph(Department department){

}

void initializeDepartments(Department arrDepartments[]){
        arrDepartments[0].setNumberAndName(0,"English Department");
        arrDepartments[1].setNumberAndName(1,"Mathematics Department");
        arrDepartments[2].setNumberAndName(2,"Computer Science Department");
        arrDepartments[3].setNumberAndName(3,"Business Department");
        arrDepartments[4].setNumberAndName(4,"Kinesiology Department");
        arrDepartments[5].setNumberAndName(5,"Architecture Department");
        arrDepartments[6].setNumberAndName(6,"Biology Department");
        arrDepartments[7].setNumberAndName(7,"Education Department");
        arrDepartments[8].setNumberAndName(8,"Chemistry Department");
        arrDepartments[9].setNumberAndName(9,"Engineering Department");

}

void initializeClassSizes(int intClassSizes[],int len){
    for(int i = 0; i < len; i++){
        intClassSizes[i] = 0;
    }
}

void menu_collect(Department& department){
    char strInput[] = " " ;
    int intClassSize = 0;
    bool blnValidInput = false;

    for(int i = 0; i < 10; i ++){
        do{
            cout << "Class sizes are from 0 - 40 Students.\n";
            printf("%d%02d ",department.getNumber(),i );
            cin >> strInput;
            intClassSize = atoi(strInput);

            blnValidInput = isInRange(intClassSize,0,40);
            if (!blnValidInput) {
                cout << "Please enter ONLY numbers 0 - 40\n";
            } 
        }while(!blnValidInput);
        department.setClassSize(i,intClassSize);
    }

}

int printMenu(Department arrDepartments[]){
    bool blnValidInput = true;
    char strInput[] = " " ;
    int intInput = 0;
    do{
        
        system("clear");  // Run the system command to clear the screen

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