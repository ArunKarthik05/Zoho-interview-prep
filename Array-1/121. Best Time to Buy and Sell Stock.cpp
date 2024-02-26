#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxProfit(vector<int>&stocks){
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto &stock:stocks){
            mini = min(mini,stock);
            maxi = max(stock-mini,maxi);
        }
        return maxi;
    }
};
int main(){
    Solution obj;
    vector<int>stocks = {7,1,5,3,6,4};
    cout<<"MAX PROFIT:"<<obj.maxProfit(stocks);
}