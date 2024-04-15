#include<iostream>
#include "Profile.h"
#include "Network.h"
using namespace std;

int main(){
    string name;
    int id = INT16_MAX;
    cout<<"Enter your name:",cin>>name;
    Profile p(name,id--);
    Profile p2("Friend",id--);
    p.addFriend(p2);
    p.getFriendsList();
    Network n;
    n.addProfile(p);
    n.getAllProfiles();
    return 0;
}