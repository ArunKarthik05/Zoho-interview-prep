#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort( nums.begin(),nums.end());
        for(auto num:nums)  cout<<num<<" ";
        int counter = 1;
        for(int i=0;i<nums.size();i++){
            if( nums[i]<=0 ) continue;
            cout<<"nums[i]:"<<nums[i]<<endl;
            cout<<"counter:"<<counter<<endl;
            if( i+1<nums.size() && nums[i] == nums[i+1] )   continue;
            if( nums[i]>0 and nums[i]!=counter)    return counter;
            else counter++;
        }
        return counter;
    }
};
int main(){
    vector<int> nums = {0,2,2,1,1};
    Solution obj;
    cout<<obj.firstMissingPositive(nums);
}