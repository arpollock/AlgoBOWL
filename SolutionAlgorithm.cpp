//
// Created by Alex Pollock on 2/19/19.
//

#include "SolutionAlgorithm.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

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
}

void SolutionAlgorithm::printValues(){
    cout << size << endl;
    for(int ele: input){
        cout << ele << " " ;
    }
}

void SolutionAlgorithm::outputToFile(){
    string fileName = "algobowl_output_size" + to_string(size) + ".txt";
    ofstream outfile(fileName);
    if(!outfile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    // TODO: output solution
    outfile.close();
    return;
}

void SolutionAlgorithm::additionSequence(){

}

vector<int> SolutionAlgorithm::getInput(){
    return input;
}

int SolutionAlgorithm::getSize(){
    return size;
}
