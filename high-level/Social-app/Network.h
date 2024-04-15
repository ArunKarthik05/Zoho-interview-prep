#ifndef NETWORK_H
#define NETWORK_H

#include<iostream>
#include<unordered_map>
#include<vector>
#include "Profile.h"
using namespace std;

class Network{
    protected:
    vector<Profile>allProfiles;
    public:
    void addProfile(Profile p){
        allProfiles.push_back(p);
        cout<<"\nSuccess.New profile created."+p.getDetails();
    }
    void getAllProfiles(){
        for( auto profile:allProfiles){
        cout<<"\n--------PROFILE DETAILS:-----------------";
        cout<<"\nName:"<<profile.name;
        cout<<"\nID:"<<profile.id;
        }
    }
};

#endif