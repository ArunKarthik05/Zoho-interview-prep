#include <iostream>
#include "Comapartment.h"
#include "Passenger.h"
#include "Train.h"
int main() {
    int noOfComp =2;
    Train train(noOfComp);
    for( int i=0;i<171;i++){
        train.bookTicket("Alice", 25, FEMALE, "lower");
        // train.bookTicket("Bob", 30, MALE, "lower");
        // train.bookTicket("Charlie", 35, MALE, "lower");
    }


    train.bookedTickets();
    cout<<"\nTotal tickets available:"<<86*noOfComp;
    return 0;
}
