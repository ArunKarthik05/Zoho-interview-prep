#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0, ones=0, twos= nums.size()-1;
        while( ones<= twos){
            if( nums[ones] == 0){
                swap(nums[zeros],nums[ones]);
                zeros++;
                ones++;
            }else if( nums[ones] == 1)  ones++;
            else{
                swap( nums[ones],nums[twos]);
                twos--;
            }
        }
    }
};
int main(){
    Solution obj;
    vector<int>nums = { 2,0,2,1,1,0 };
    obj.sortColors(nums);
    for( auto &el:nums) cout<<el<<",";
}