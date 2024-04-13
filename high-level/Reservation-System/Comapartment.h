#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include <iostream>
#include<unordered_map>
#include <string>
using namespace std;
class Compartment{
    public:
    int upper[21];
    int middle[21];
    int lower[21];
    int racSeats[18];

    unordered_map<string,int> remainingSeats;  
    bool isFull;
    Compartment(){
        isFull = false;
        remainingSeats["upper"] = 21;
        remainingSeats["middle"] = 21;
        remainingSeats["lower"] = 21;
        remainingSeats["rac"] = 18;
    }
    


};
#endif