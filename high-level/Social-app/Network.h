#ifndef NETWORK_H
#define NETWORK_H

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include "Profile.h"
using namespace std;

class Network{
    protected:
    unordered_map<int,vector<Profile>> allProfiles;
    public:

    void addProfile(Profile p){
        allProfiles[p.id].push_back(p);
        cout<<"\nSuccess.New profile created."+p.getDetails();
    }

    void getAllProfiles(){
        cout<<"\n--------ALL PROFILE DETAILS:-----------------";
        for( auto [id,profile]:allProfiles){
            cout<<"\nName:"<<profile[0].name;
            cout<<"\nID:"<<profile[0].id;
        }
    }

    void getProfile( int id ){
        cout<<"\n----------FIND PROFILE BY ID-----------";
        auto it = allProfiles.find(id);
        if( it!= allProfiles.end() )
            cout<<"\nName:"<<allProfiles[id][0].name;
        else
            cout<<"\nProfile not found..";
    }
};

#endif