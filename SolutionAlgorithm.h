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
#include <utility>
#include <map>

using namespace std;

class SolutionAlgorithm {
public:

    const int LOWER_BOUND = 1; // positive integers
    const int UPPER_BOUND = 1000000000; // 10^7 //1000000000; // 10^9

    // Getters, Setters, & Print Help
    vector<int> getInput();
    int getSize();
    void printValues();

    // Create Input
    void createInput(int length);

    // Interpret Input File
    void readInput(string fileName);

    // Create Output
    void additionSequence();
    void postProcessing();

    // Verify Established Input
    bool validInputSize();
    bool validInputSort();
    bool validInputValues();

    // Verify Established Output
    bool validOutput( string fileOutputName );

    // Output input to File
    void inputToFile();

    // Output output to File
    void outputToFile( string fileName );

private:
    bool secondRound;
    vector<int> input;
    int size;
    vector<pair<int, int>> solution;
    vector<pair<int,int>> oldSolution;
    int oldSize;

};


#endif //ALGOBOWL_SOLUTIONALGORITHM_H
