#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(),inx=-1,count=0;
        for( int i=0;i<n;i++){
            if( nums[i] and inx == -1){
                inx = i;
            }
            if( nums[i] == 0 and inx>=0 ){
                swap( nums[i],nums[inx]);
                inx++;
            }
        }
        cout<<"COUNT:"<<count;
    }
};
int main(){
    Solution obj;
    vector<int>nums = { 0,0,0,0,0,1,0,1,0,0,1};
    obj.sortColors(nums);
    for( auto &el:nums) cout<<el<<",";
}