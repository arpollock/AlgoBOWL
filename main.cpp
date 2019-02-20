#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "InputGenerator.h"
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
    cout << "(2) Generate Output from Input" << endl;
    cout << "(3) Verify Input" << endl;
    cout << "(4) Verify Output" << endl;
    int choice = 0;
    bool validChoice = false;

    while(!validChoice){
        cout << "Your choice: ";
        cin >> choice ;
        validChoice = isValidChoice(choice);
    }

    switch(choice) {
        case 1: {

            int mySize;
            cout << "Enter the size of the list (must be [2, 1000]): ";
            cin >> mySize;
            vector<int> myList = createList(mySize);
            cout << "Is sorted? " << isSorted(myList) << endl;
            cout << "Is vaild size? " << validSize(myList.size()) << endl;
            cout << "***** Generating output file *****" << endl;
            outputToFile(mySize, myList);

            break;
        }
        case 2: {

            cout << "Chose input file name (include .txt at the end): ";
            string fileName = "";
            cin >> fileName;
            SolutionAlgorithm verify;
            verify.readInput(fileName);
            verify.printValues();

            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        deafult: {
            cout << "Unrecognized Input" << endl;
            break;
        }
    }

    return 0;
}