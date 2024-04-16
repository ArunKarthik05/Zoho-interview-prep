#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> oneSum(vector<int> &nums, int target){
        unordered_map<int, int> pairIdx;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (pairIdx.find(target - num) != pairIdx.end()) {
                return {i, pairIdx[target - num]};
            }
            pairIdx[num] = i;
        }

        return {};  
    }
};
int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    Solution obj;
    vector<int> ans = obj.oneSum(arr,target);
    cout<<"\nans:";
    for( auto el: ans){
        cout<<el<<" ";
    }
}