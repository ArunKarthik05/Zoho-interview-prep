#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findSum(vector<int> nums, int target){
        vector<vector<int>> ans;
        int sum =0;
        for( int i=0;i<nums.size();i++){
            if( nums[i]+sum > target)    continue;
            vector<int> temp;
            int inx = i;
            sum += nums[inx];
            temp.push_back(nums[inx]);
            while( sum<target){
                auto it = find(nums.begin()+i,nums.end(),target-sum);
                int index = distance(nums.begin(),it);
                if( index< nums.size() ){
                    temp.push_back(nums[index]);
                    sum += nums[index];
                }
            }

        }
        return ans;
    }
};
int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    Solution obj;
    vector<vector<int>> ans = obj.findSum( nums, target);
        for( auto row: ans){
            for (auto el:row){
                cout<<el<<" ";
            }
    }
}