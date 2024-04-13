#include<bits/stdc++.h>
using namespace std;

void getAvailableSeats( string preference ){
    vector<string> preferences = { "lower","middle","upper"};
    auto it = find(preferences.begin(),preferences.end(),preference); 
    int index = distance( preferences.begin(),it);
    vector<int> visIndexes;
    visIndexes.push_back(index);
    while( visIndexes.size()<3){
        index++;
        if( index >2){
            index =0;
        }
        visIndexes.push_back(index);
    }   
}
int main(){
    getAvailableSeats("upper");
}