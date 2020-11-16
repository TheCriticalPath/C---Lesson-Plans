#include <iostream> // Needed for stdout
#include <fstream>  // Needed for File stream
#include <vector>   // Needed for vector
#include <iterator> // Needed for iterator
#include <algorithm>// Needed for ?
#include <math.h>   //
#include <ctime>    // Needed for time() random number generator

#define FILENAME "./simpleFile.txt"
using namespace std;

// Function Prototypes
void readFile (string,vector<string>&);

int main(){
    //open the file
    vector<string> vctFileContents;
    readFile("./simpleFile.txt",vctFileContents);
    
    //Seed the random number generator
    srand((int) time(0));
    double position = 0.0;
    cout << vctFileContents.size() << endl;
    vctFileContents.shrink_to_fit();
    vctFileContents.begin();
    vector<double> vctPosition;
    for (int i = 0; i < 50;i++){
        do{
           position = rand() % vctFileContents.size();
        }while(find(vctPosition.begin(), vctPosition.end(), position) != vctPosition.end());
        cout << vctFileContents[position] << endl;
        vctPosition.push_back(position);

    }
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