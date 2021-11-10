#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//function to check for errors in input
string binaryProcessing(string line) {
    //declare variables
    bool numberPassed = false;
    string newLine;
    char lineChar;

    //loop through all the inputs and look for errors
    for (int i = 0; i < line.length(); i++) {
        lineChar = line.at(i);

        //check if the number 1 has passed yet
        if (lineChar == '1') {
            newLine.push_back(lineChar);
            numberPassed = true;
        }
        //if 1 has passed then 0 can too
        else if (lineChar == '0' && numberPassed) {
            newLine.push_back(lineChar);
        }
        //do nothin if this comes up (aka it wont be added to newLine)
        else if(lineChar == '_' && !numberPassed) {
            
        }
        //if there is a char that is not 0, 1, or _, then the number will be void
        else if(lineChar != '0'){
            return "Bad digit on input";
        }
    }
    return newLine;
}

//function to turn binary to decimal
int binaryToDecimal(string binaryLine) {
    //declaring variables
    int base = 1;
    int decimalLine = 0;

    //loop through the string backwards
    for (int i = binaryLine.size() - 1; i >= 0; i--) {
        //if the number doesnt start with 1 the 0's will be ignored until a 1 shows
        if (binaryLine[i] == '1') {
            //if a 1 is detected then add a 1 and multiply it by 2 squared to the amount of times the loop has ran
            decimalLine += base;
        } 
        base *= 2;
    }

    return decimalLine;
}

int main()
{
    //prepping the file
    ifstream inFile;
    inFile.open("BinaryIn.dat");

    //declaring variables
    string line;
    vector<string> binaryNumbers;
    int n;

    //taking the data from the file and assigning it to a vector while checking them for errors
    while (getline(inFile, line)) {
        binaryNumbers.push_back(binaryProcessing(line));
    }
    
    //looping through the processed variables and turning them into decimal
    for (int i = 0; i < binaryNumbers.size(); i++) {
        n = binaryToDecimal(binaryNumbers[i]);
        if (n == 0) {
            cout << "Bad digit on input" << endl;
        }
        else {
            cout << n << endl;
        }
    }
}