#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = INT_MIN, count =0;
        for(auto &num:nums){
            mp[num]++;
            if( mp[num]>maxi)   maxi = mp[num];
        }
        cout<<"max"<<maxi<<endl;
        for( auto num:mp){
            cout<<num.second<<endl;
            if( num.second== maxi )  count++; 
        }
        cout<<"final"<<count;
        return count;
    }
};
int main(){
    vector<int> nums =  {1,2,2,3,1,4};
    Solution obj;
    cout<<"count:"<<obj.maxFrequencyElements( nums );
}