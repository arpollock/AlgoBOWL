//
// Created by Alex Pollock on 2/19/19.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int lowerBound = 1; // positive integers
const int upperBound = 1000000000; // 10^9

vector<int> createList(int length){
    vector<int> intList;
    for(int i = 0 ; i < length ; i++){
        int ele = rand() % (upperBound-lowerBound) + lowerBound;
        intList.push_back(ele);
    }

    sort(intList.begin(), intList.end());


    return intList;
}

bool validSize(int size){
    if(size >=2 && size<=1000 ){
        return true;
    }
    return false;
}

bool isSorted( const vector<int>& vect){
    for(int i = 1 ; i < vect.size(); i++ ){
        if( vect.at(i-1) > vect.at(i) ){
            return false;
        }
    }
    return true;
}

void outputToFile( const int size, const vector<int>& vect){
    string fileName = "algobowl_input_size" + to_string(size) + ".txt";
    ofstream outfile(fileName);
    if(!outfile.is_open()){
        cerr << "Error opening output file" <<endl;
    }
    outfile << size << endl;
    for(int ele: vect){
        outfile << ele << " " ;
    }
    outfile.close();
    return;
}