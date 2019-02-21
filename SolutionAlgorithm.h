//
// Created by Alex Pollock on 2/19/19.
//

#ifndef ALGOBOWL_SOLUTIONALGORITHM_H
#define ALGOBOWL_SOLUTIONALGORITHM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class SolutionAlgorithm {
public:
    void readInput(string fileName);
    void printValues();
    void outputToFile();
    void additionSequence();
    vector<int> getInput();
    int getSize();
    bool validOutput();

private:
    vector<int> input;
    int size;

};


#endif //ALGOBOWL_SOLUTIONALGORITHM_H
