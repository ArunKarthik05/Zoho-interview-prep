#ifndef PASSENGER_H
#define PASSENGER_H

#include<string>

using namespace std;

enum GenderType {
    MALE,
    FEMALE
};

class Passenger{
    private:
    string name;
    int age;
    GenderType gender;
    string birthPreference;
    bool withChildren;
    Passenger* child;
    public:
    Passenger(string name, int age, GenderType gender, string birthPreference, bool withChildren) 
    : name(name), age(age), gender(gender), birthPreference(birthPreference), withChildren(withChildren), child(nullptr) {}
    
    Passenger(string name, int age, GenderType gender) 
    : name(name), age(age), gender(gender) {}
    
    Passenger(string name, int age, GenderType gender, string birthPreference) 
    : name(name), age(age), gender(gender), birthPreference(birthPreference) {}
    

};
#endif 