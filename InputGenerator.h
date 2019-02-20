//
// Created by Alex Pollock on 2/19/19.
//

#ifndef ALGOBOWL_INPUTGENERATOR_H
#define ALGOBOWL_INPUTGENERATOR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> createList(int length);

bool validSize(int size);

bool isSorted( const vector<int>& vect);

void outputToFile( const int size, const vector<int>& vect);

#endif //ALGOBOWL_INPUTGENERATOR_H
