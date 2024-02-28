#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findusingFormula(vector<int>&val){
        int maxi = *max_element(val.begin(),val.end());
        int totalSum =( maxi * (maxi+1) )/2;
        int sum =0;
        for( auto &el:val)  sum += el;
        return sum-totalSum;
    }
    int slowandFast( vector<int>nums ){
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow; // or fast, as they meet at the same point
    }
};
int main(){
    vector<int>val = {1,3,4,5,5,2};
    Solution obj;
    int ans1 = obj.findusingFormula(val);
    cout<<"The extra no is using formula:"<<ans1;
    int ans2 = obj.findusingFormula(val);
    cout<<"\nThe extra no is using HORSE & TORTOISE:"<<ans2<<endl;
}