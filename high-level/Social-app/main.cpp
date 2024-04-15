#include<iostream>
#include "Profile.h"
#include "Network.h"
using namespace std;

int main(){
    string name;
    int id = INT16_MAX;
    cout<<"Enter your name:",cin>>name;

    Profile p(name,id--);
    Profile p2("Ajay",id--);
    Profile p3("John",id--);
    
    p.addFriend(p2);
    p2.addFriend(p);
    p.addFriend(p3);
    p.getFriendsList();
    p2.getFriendsList();

    Network n;
    n.addProfile(p);
    n.addProfile(p2);
    n.addProfile(p3);
    n.getAllProfiles();
    n.getProfile(32767);
    n.getProfile(327672);
    
    cout<<endl;
    return 0;
}