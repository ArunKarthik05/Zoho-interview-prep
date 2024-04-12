#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include <iostream>
class Compartment{
    private:
    int upper[21];
    int middle[21];
    int lower[21];
    int racSeats[18];

    int remainingTickets[4] = { 21,21,21,18 };
    bool isFull = false;
};
#endif