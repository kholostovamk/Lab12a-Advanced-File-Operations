#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct FileText
{
     int lineNumber;
     long long fileOffset; // (use long long to prevent compiler warning)
     int length;
     string contents;
};

int main () {
    fstream myFile;
    ofstream myFileOut;
    string fileName;
    
    int arrayIndex = 0; //counter for the loop
    
    int lineNumber = 0; //initializing line number
    int size = 1000;
    FileText array[size]; //adding array into struct

    cout << "Enter name of input/output file: " << endl;
    cin >> fileName;

    int offset = 0;
    myFile.open(fileName.c_str()); // open file

    while (getline(myFile, array)){
        lineNumber++;
        array[arrayIndex].lineNumber = lineNumber;
        array[arrayIndex].fileOffset = offset;
        arrayIndex++;
        offset = myFile.tellg();
        offset += lineNumber;
    }
}