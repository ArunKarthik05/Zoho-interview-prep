#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> findMaxInRange( vector<int> &arr,int range ){
        vector<int> ans;
        int inx= -1;
        for(int i=0;i<=arr.size()-range;i++){
            int maxVal = -1;
            int newInx = -1;
            if( inx >=i ){
                cout<<"\nLast max value is at"<<inx<<" which is within range";
                ans.push_back( arr[inx]);
                continue;
            }
            for( int j=i;j<i+range;j++){
                cout<<"\nCurr j:"<<j;
                cout<<"\nMAXVAL:"<<maxVal;
                if( arr[j]>maxVal ){
                    maxVal = arr[j];
                    cout<<"\nNew max:"<<maxVal<<" at "<<j;
                    newInx = j;
                }
            }
            ans.push_back( maxVal );
            inx = newInx;
            cout<<"\nPushing new val:"<<maxVal<<",index:"<<inx;
        }
        return ans;
    }
};
int main(){
    vector<int> arr = {6,5,2,1,9,3,5,2};
    int range = 3;
    Solution obj;
    vector<int>ans = obj.findMaxInRange(arr,range);
    cout<<"\nans:"<<endl;
    for( auto el:ans){
        cout<<el<<" ";
    }
}