#ifndef PROFILE_H
#define PROFILE_H

#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Network;

class Profile{
    protected:
    string name;
    int id;
    unordered_map<int,vector<Profile>> friendsList;
    
    public:
    Profile( string name,int id) : name(name),id(id){}

    string getDetails(){
        string Details = "Name:"+name+",Id:"+to_string(id);
        return Details;
    }
    
    void addFriend(Profile p){
        friendsList[p.id].push_back(p);
    }

    void getFriendsList(){
        cout<<"\n----------FRIENDSLIST OF "<<name<<"-----------";
        for( auto [id,profiles]:friendsList){
            for( auto p:profiles){
                cout<<"\nName("<<p.id<<")"<<p.name;
            }
        }
    }
    friend class Network;
};

#endif