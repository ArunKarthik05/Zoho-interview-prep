#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void merge(vector<int>& v1, vector<int>& v2) {
        int sz1 = v1.size();
        int sz2 = v2.size();
        int left=sz1-1,right=0;
        while( right<sz2 ){
            if( v2[right]< v1[left] ){
                int swapVal = v1[left];
                int swapper = left-1;
                while( swapper>=0 and v2[right] < v1[swapper] ){
                    v1[swapper+1] = v1[swapper];
                    swapper--;
                }
                v1[swapper+1] = v2[right]; 
                v2[right] = swapVal;
            }
            right++;
        }
    }
};
int main(){
    vector<int>v1 = {0,1,8,10};
    vector<int>v2 = {5,3,9};
    Solution obj;
    obj.merge(v1,v2);
    for( auto &el:v1)
        cout<<el<<" ";
}