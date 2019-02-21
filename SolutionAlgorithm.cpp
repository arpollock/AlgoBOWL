//
// Created by Alex Pollock on 2/19/19.
//

#include "SolutionAlgorithm.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <set>
#include <utility>
using namespace std;

vector<int> SolutionAlgorithm::getInput(){
    return input;
}

int SolutionAlgorithm::getSize(){
    return size;
}

void SolutionAlgorithm::printValues() {
    cout << size << endl;
    for (int ele: input) {
        cout << ele << " ";
    }
}

void SolutionAlgorithm::createInput(int length){
    size = length;
    vector<int> intList;
    for(int i = 0 ; i < length ; i++){
        int ele = rand() % (UPPER_BOUND-LOWER_BOUND) + LOWER_BOUND;
        intList.push_back(ele);
    }

    sort(intList.begin(), intList.end());
    input = intList;
    return;
}

void SolutionAlgorithm::readInput(string fileName){
    ifstream inFile(fileName);
    if(!inFile.is_open()){
        cerr << "Error opening input file" <<endl;
    }
    inFile >> size;
    for( int i = 0 ; i < size ; i++ ){
        int val = -1;
        inFile >> val;
        input.push_back(val);
    }
    inFile.close();
}

void SolutionAlgorithm::additionSequence(){
    //set<int> validOperands;
    //validOperands.insert(1); // 1 is always a valid operand


    int currentVal = 1;
    for(int ele: input){
        bool summedTo = false;
        while(!summedTo){
            pair<int,int> currentAddition;
            currentAddition.first = currentVal;
            currentAddition.second = 1;
            solution.push_back(currentAddition);
            currentVal +=1;
            if(currentVal==ele){
                summedTo = true;
            }
        }
    }
}

bool SolutionAlgorithm::validInputSize(){
    if(size >=2 && size<=1000 ){
        return true;
    }
    return false;
}

bool SolutionAlgorithm::validInputSort(){
    for(int i = 1 ; i < input.size(); i++ ){
        if( input.at(i-1) > input.at(i) ){
            return false;
        }
    }
    return true;
}

bool SolutionAlgorithm::validInputValues(){
    for(int value: input){
        if(  value < LOWER_BOUND || value > UPPER_BOUND){
            return false;
        }
    }
    return true;
}

bool SolutionAlgorithm::validOutput(string fileOutputName){

    ifstream inFile(fileOutputName);
    if(!inFile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    int rows = 0;
    inFile >> rows;
    vector<int> output;
    set<int> validOperands;
    validOperands.insert(1); // 1 is the only valid operand from the beginning

    for( int i = 0 ; i < rows ; i++ ){
        int val1 = -1;
        int val2 = -1;
        inFile >> val1;
        inFile >> val2;
        if( val1 > 0 && val2 > 0 ) {
            if( validOperands.count(val1) == 0 || validOperands.count(val2)==0 ) {
                inFile.close();
                cout << "INVALID: using invalid operand." << endl;
                return false;
            }else {
                int sum = val1 + val2;
                validOperands.insert(sum);
            }
        }else {
            inFile.close();
            cout << "INVALID: negative operand or invalid file format." << endl;
            return false;
        }
    }
    inFile.close();
    for(int ele: input){
        if( validOperands.count(ele)==0 ){
            cout << "INVALID: does not sum to all elements in input." << endl;
            return false;
        }
    }

    return true;

}

void SolutionAlgorithm::inputToFile(){
    string fileName = "algobowl_input_size" + to_string(size) + ".txt";
    ofstream outfile(fileName);
    if(!outfile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    outfile << size << endl;
    for(int ele: input){
        outfile << ele << " " ;
    }
    outfile.close();
    return;
}

void SolutionAlgorithm::outputToFile(){
    string fileName = "algobowl_output_size" + to_string(size) + ".txt";
    ofstream outfile(fileName);
    if(!outfile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    outfile << solution.size() << endl;
    for(auto currentAddition: solution){
        outfile << currentAddition.first << " " << currentAddition.second << endl;
    }
    outfile.close();
    return;
}