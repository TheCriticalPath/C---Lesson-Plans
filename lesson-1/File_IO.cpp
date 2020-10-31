#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <ctime>

#define FILENAME "./simpleFile.txt"
using namespace std;

// Function Prototypes
void readFile (string,vector<string>&);

int main(){
    //open the file
    vector<string> vctFileContents;
    readFile(FILENAME,vctFileContents);
    srand((int) time(0));
    
    cout << vctFileContents.size() << endl;
    vctFileContents.shrink_to_fit();
    vctFileContents.begin();
    double position = rand() % vctFileContents.size();
    cout << vctFileContents[position] << endl;
    vctFileContents.clear();

}

void readFile(string fileName,vector<string>& vctFileContents){
    //vctFileContents;
    string strLine = "";
    ifstream fileInput;
    long lineCounter = 0;
    fileInput.open(fileName,ios::in);
    if(fileInput.is_open()){
        while (fileInput.good()){
            getline(fileInput,strLine);
            vctFileContents.push_back(strLine);
            lineCounter++;
            //cout << vctFileContents[lineCounter-1] << endl;
        }
    }
    cout << lineCounter << endl;

}