#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "SolutionAlgorithm.h"

using namespace std;

bool isValidChoice(int choice){
    if( choice == 1 || choice == 2 || choice == 3 || choice == 4 ){
        return true;
    }
    return false;
}

int main() {

    srand(time(0));

    cout << "Options:" << endl;
    cout << "(1) Generate Input" << endl;
    cout << "(2) Generate Output from Input (& Verify Output)" << endl;
    cout << "(3) Verify Input" << endl;
    cout << "(4) Verify Output" << endl;
    int choice = 0;
    bool validChoice = false;

    while(!validChoice){
        cout << "Your choice: ";
        cin >> choice ;
        validChoice = isValidChoice(choice);
    }

    SolutionAlgorithm verify;

    switch(choice) {
        case 1: {

            int mySize;
            cout << "Enter the size of the list (must be [2, 1000]): ";
            cin >> mySize;
            verify.createInput(mySize);
            cout << "***** Generating output file *****" << endl;
            verify.inputToFile();

            break;
        }
        case 2: {

            cout << "Chose input file group number (e.g. 91): ";
            string num = "";
            cin >> num;
            string fileNameIn = "./inputs/input_group";
            string fileNameOut = "./outputs/output_group";
            fileNameIn = fileNameIn + num + ".txt";
            fileNameOut = fileNameOut + num +".txt";

            verify.readInput(fileNameIn);
            //verify.printValues();
            verify.additionSequence();
            verify.postProcessing();
            //cout << "Chose output file name (include .txt at the end): ";
            //cin >> fileName;
            verify.readInput(fileNameIn);
            verify.outputToFile(fileNameOut);
            cout << "Valid output?  " << verify.validOutput(fileNameOut) << endl;

            break;
        }
        case 3: {
            cout << "Chose input file name to verify (include .txt at the end): ";
            string fileName = "";
            cin >> fileName;
            verify.readInput(fileName);
            cout << "Is sorted? " << verify.validInputSort() << endl;
            cout << "Is vaild size? " << verify.validInputSize() << endl;
            cout << "Valid element values? " << verify.validInputValues() << endl;
            break;
        }
        case 4: {
            //cout << "Chose input file name to check output against (include .txt at the end): ";
            //string fileName = "";
            //cin >> fileName;
            cout << "Chose input file group number (e.g. 91): ";
            string num = "";
            cin >> num;
            string fileNameIn = "./inputs/input_group";
            string fileNameOut = "./outputs/output_group";
            fileNameIn = fileNameIn + num + ".txt";
            fileNameOut = fileNameOut + num +".txt";
            verify.readInput(fileNameIn);

            //cout << "Chose output file name to verify (include .txt at the end): ";
            //cin >> fileName;
            cout << "Valid output?  " << verify.validOutput(fileNameOut) << endl;
            break;
        }
        default: {
            cout << "Unrecognized Input" << endl;
            break;
        }
    }

    return 0;
}