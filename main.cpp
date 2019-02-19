#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int lowerBound = 1; // positive integers
const int upperBound = 10;//1000000000; // 10^9

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

int main() {
    srand(time(0));

    std::cout << "Hello, World!" << std::endl;
    int mySize = 5;
    vector<int> myList = createList(mySize);
    if(validSize(myList.size())){
        for(int ele: myList){
            cout << ele << " " ;
        }
    }
    return 0;
}