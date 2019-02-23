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
#include <map>
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
    input.clear();
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
    vector<int> validOperands;
    validOperands.clear();
    validOperands.push_back(1); // 1 is always a valid operand
    for(int ele: input){
//        cout << "Valid Operands: ";
//        for(int ele: validOperands){
//            cout << ele <<" ";
//        }
//        cout<< endl;

        int currentMax = 0;
        pair<int,int> addition;
        addition.first = validOperands.at(validOperands.size()-1);
        addition.second = validOperands.at(validOperands.size()-1);
        int currentSum = addition.first + addition.second; // add the biggest operand to itself

        int difference = ele - currentSum;

        while(difference != 0){
            if( difference < 0 ){
                // take the next biggest (for one number) and try again
                currentMax++;
                if( addition.first > addition.second ){
                    addition.first = validOperands.at(validOperands.size()-1-currentMax);
                }else{  // second is greater or equal
                    addition.second = validOperands.at(validOperands.size()-1-currentMax);
                }
                currentSum = addition.first + addition.second;
            }else if(difference > 0){
                // operation is moving toward goal, add to addition sequence

                if( find(validOperands.begin(), validOperands.end(), currentSum) == validOperands.end() ){
                    // not already a calculated number
                    solution.push_back(addition);
                    validOperands.push_back(currentSum);
                }

                bool foundNextBiggest = false;
                int i = validOperands.size()-1; // start at the end of the list
                int valueToAdd = 1;
                if(difference == 1 ){ //only need to add one
                    foundNextBiggest = true;
                }
                while( !foundNextBiggest && i>=0 ){
                    if( validOperands.at(i)<=difference ){
                        valueToAdd = validOperands.at(i);
                        foundNextBiggest = true;

                    }
                    i--;
                }
                addition.first = currentSum;
                addition.second = valueToAdd;
                //solution.push_back(addition);
                currentSum+=valueToAdd;
            }

            difference = ele - currentSum;
        }
        if( find(validOperands.begin(), validOperands.end(), currentSum) == validOperands.end() ){
            // not already a calculated number
            solution.push_back(addition);
            validOperands.push_back(currentSum);
        }
    }
}

void SolutionAlgorithm::postProcessing(){
    // save the old addition sequence in case it is better (i.e. for small inputs)
    oldSolution = solution;
    oldSize = size;
    map<int, int> sumCounter;
    // get all the sums of consecutive additions
    for(int i = 1; i < solution.size(); i++){
        int currSum;
        currSum = solution.at(i-1).second + solution.at(i).second;
        if(sumCounter.count(currSum)==0){
            sumCounter.insert(pair<int,int>(currSum,1));
        }else{
            sumCounter.at(currSum)++;
        }
    }
    // find the frequency of those sums
    for(pair<int,int> kv: sumCounter){
        //cout << kv.first << " " <<kv.second << endl;
        if(kv.second > 2 && find(input.begin(), input.end(), kv.first) == input.end() ){
            // not already a calculated number & is calculated multiple times
            input.push_back(kv.first);
        }
    }

    sort(input.begin(), input.end());
    size = input.size();
    solution.clear();
//    for(int ele: input){
//        cout << ele <<endl;
//    }
    additionSequence();
    if(solution.size()<oldSolution.size()){
        oldSolution = solution;
        oldSize = size;
        postProcessing();
    }
//    map<int,int>::iterator it = sumCounter.begin();
//
//    while(it != sumCounter.end()){
//        cout << it->first << " " << it->second << endl;
//        it++;
//    }
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
                cout << "INVALID: using invalid operand at row " << i-2 << endl;
                cout << "val1: " << val1 << " val2: " << val2 <<endl;
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

void SolutionAlgorithm::outputToFile(string fileName){
    ofstream outfile(fileName);
    if(!outfile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    if( solution.size() < oldSolution.size() ){
        outfile << solution.size() << endl;
        for(auto currentAddition: solution){
            outfile << currentAddition.first << " " << currentAddition.second << endl;
        }
    }else{
        outfile << oldSolution.size() << endl;
        for(auto currentAddition: oldSolution){
            outfile << currentAddition.first << " " << currentAddition.second << endl;
        }
    }

    outfile.close();
    return;
}