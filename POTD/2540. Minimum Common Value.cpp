#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        int left =0, right =0, ans=-1;
        while( left<n1.size() and right<n2.size() ){
            if( n1[left]<n2[right]) left++;
            else if( n1[left]>n2[right] )   right++;
            else{
                ans = n1[left];
                break;
            }            
        }
        return ans;
    }
};
int main(){
    vector<int>nums1 = {1,2,3,6};
    vector<int>nums2 = {2,3,4,5};
    Solution obj;
    cout<<"Ans:"<<obj.getCommon(nums1, nums2);
}