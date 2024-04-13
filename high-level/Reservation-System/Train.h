#ifndef TRAIN_H
#define TRAIN_H

#include<vector>
#include<ctime>
#include <algorithm>
using namespace std;
#include "Comapartment.h"
#include "Passenger.h"

class Train{
    private:
    vector<Compartment*> compartments;
    int remainingCompartments;
    vector<int> passengers;
    vector<int> waitingList;
    int TrainNo;
    public:

    Train(int noOfCompartments) : waitingList(0) {
        time_t now = time(nullptr);
        TrainNo = now;
        this->remainingCompartments = noOfCompartments;
        compartments.reserve(noOfCompartments);
        for( int i=0;i<noOfCompartments;i++){
            compartments.push_back(new Compartment());
        }
    }

    void bookedTickets(){
        for(int i=0;i<compartments.size();i++){
            cout<<"\nCompartment:"<<i+1;
            cout<<"\nTickets remaining:";
            cout<<"\nLower:"<<compartments[i]->remainingSeats["lower"];
            cout<<"\nUpper:"<<compartments[i]->remainingSeats["upper"];
            cout<<"\nmiddle:"<<compartments[i]->remainingSeats["middle"];
        }
    }

    pair<string,int> getAvailableSeats( string preference ){
        vector<string> preferences = { "lower","middle","upper"};
        auto it = find(preferences.begin(),preferences.end(),preference); 
        int index = distance( preferences.begin(),it);

        cout<<"\nYour Preference:"<<preferences[index];

        vector<int> visIndexes;
        visIndexes.push_back(index);
        unordered_map<string, int> FreeCompartments;
        bool ticketBooked = false;

        while( visIndexes.size()<3 && ticketBooked == false){
            FreeCompartments["lower"] = FindFreeCompartment("lower"); 
            FreeCompartments["middle"] = FindFreeCompartment("middle"); 
            FreeCompartments["upper"] = FindFreeCompartment("upper"); 
            string currPreference = preferences[index];
            cout<<"\n---------------";
            cout<<"\nPreference:"<<currPreference;
            while( FreeCompartments[currPreference] == -1 && visIndexes.size()<3){
                cout<<"---------------------------------------";
                    index++;
                    cout<<"\nUpdated to:"<<preferences[index];
                    if( index > 2){
                        index =0;
                    }

                    visIndexes.push_back(index);
                    for( auto x:visIndexes){
                            cout<<x<<",";
                    }
                    cout<<endl;
                    currPreference = preferences[index];
                }
                if( visIndexes.size()==3 ){
                    ticketBooked = true;
                    if( FreeCompartments[currPreference] == -1 )
                        return getRacSeats();
                }
            cout<<"\ncurrentComp:"<<FreeCompartments[currPreference];
            Compartment* currentComp = compartments[FreeCompartments[currPreference]];
            // if( currentComp->remainingSeats[currPreference] >0 ){
                cout<<"\nRemaining Seats in "<<currPreference<<"is:"<<currentComp->remainingSeats[currPreference];
                int seatno=0;
                while( seatno<22){
                    if (currPreference == "lower" && currentComp->lower[seatno] == NULL) {
                        currentComp->remainingSeats[currPreference]--;
                        currentComp->lower[seatno] = 1;
                        cout<<"\nReturning Seatno:"<<seatno;
                        ticketBooked = true;
                        return { currPreference, seatno };
                    }
                    else if (currPreference == "middle" && currentComp->middle[seatno] == NULL) {
                        currentComp->remainingSeats[currPreference]--;
                        currentComp->middle[seatno] = 1;
                        ticketBooked = true;
                        return { currPreference, seatno };
                    }
                    else if (currPreference == "upper" && currentComp->upper[seatno] == NULL) {
                        currentComp->remainingSeats[currPreference]--;
                        currentComp->upper[seatno] = 1;
                        ticketBooked = true;
                        return { currPreference, seatno };
                    }
                    seatno++;
                }
            
        }
        return getRacSeats();
    }

    int FindFreeCompartment( string preference ){
        cout<<"\nSize:"<<compartments.size();
        for(int i=0;i<compartments.size();i++){
            if( compartments[i]->remainingSeats[preference]>0){
                cout<<"\nThe free compartment for "<<preference<<"is:"<<i;
                return i;
            }
        }
        cout<<"\nNo free compartments for "<<preference;
        return -1;
    }
    pair<string,int> getRacSeats(){
        for( auto currentComp: compartments ){
            if( currentComp->remainingSeats["rac"] >0 ){
                int SeatNo = 19 -  currentComp->remainingSeats["rac"];
                currentComp->remainingSeats["rac"]--;
                cout<<"\nRAC remianing seats:"<<currentComp->remainingSeats["rac"];
                return { "rac", SeatNo};
            }
        }
        return getWaitingList();
    }

    pair<string,int> getWaitingList(){
        cout<<"\nFetching WL........";
        if( waitingList.size()<= 5 ){
            waitingList.push_back(1);
            return { "WL", waitingList.size()};
        }else{return {" No Tickets Available", -1};}
    }

    void bookTicket(string name, int age, GenderType gender, string preference){
        pair<string,int> TickDetails =  getAvailableSeats(preference);
        cout<<"\nYour Ticket detail is "<<TickDetails.second<<"["<<TickDetails.first<<"]";
    }


    ~Train(){
        for( auto compartment: compartments){
            delete compartment;
        }
    }
};  

#endif