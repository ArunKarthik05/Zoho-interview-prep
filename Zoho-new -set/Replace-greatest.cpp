#include<bits/stdc++.h>
using namespace std;
void Replace(vector<int> &array){
    int maxel= INT_MIN, inx=-1;
    for(int i=0;i<array.size()-1;i++){
        maxel = INT_MIN;
        for( int j=i+1;j<array.size();j++){
            if( array[j]>maxel ){
                maxel = max(maxel, array[j]);
                inx = j;
            }
        }
        cout<<"The max el is :"<<maxel<<endl;
        array[i] = maxel;
    }
    array[array.size()-1] = -1;
}

int findMax(int st,int end,vector<int> &array){
    int ans = INT_MIN,inx =-1;
    for(int start=st;start<=end;start++){
        if( array[start]>ans ){
            ans = array[start];
            inx = start;
        }
    }
    cout<<"\nThe new gretest el:"<<array[inx];
    return inx;
}


void Optimized(vector<int> &array){
    int size= array.size()-1;
    int inx = findMax(1,size,array);
    for(int i=0;i<array.size()-1;i++){
        if( i>= inx){
            cout<<"\nFdinding new max at"<<array[i]<<"at"<<i;
            inx = findMax(i+1,size, array);
        }
        array[i] = array[inx];
    }
    array[size] = -1;
}
int main(){
    vector<int> array = { 6, 5, 2, 8, 1, 7};
    // Replace(array);
    Optimized(array);
    cout<<"\nANS:"<<endl;
    for( auto nums:array){
        cout<<nums<<",";
    }
}