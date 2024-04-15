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
    unordered_map<int,string> friendsList;
    
    public:
    Profile( string name,int id) : name(name),id(id){}

    string getDetails(){
        string Details = "Name:"+name+",Id:"+to_string(id);
        return Details;
    }
    void addFriend(Profile p){
        friendsList[p.id] = p.name;
    }

    void getFriendsList(){
        for( auto [id,name]:friendsList){
            cout<<"\nFriendname("<<id<<"):"<<name;
        }
    }
    friend class Network;
};

#endif