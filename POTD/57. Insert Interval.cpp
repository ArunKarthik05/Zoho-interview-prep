#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> ans = {0 , 0 };
        vector<vector<int>> merged;
        if( intervals.size() ==0 ){
            merged.push_back( newInterval );
        }
        for(auto &interval:intervals){
            int start = interval[0];
            int end = interval[1];
            if( newInterval[0] <= end && newInterval[0] >= start ){
                ans[0] = max( start, ans[0]);
            }
                    // cout<<"\nans:"<<ans[0]<<","<<ans[1]<<endl;
            if( newInterval[1] <= end && newInterval[1] >= start){
                ans[1] = max(end,ans[1]);
            }
            if( (start > newInterval[0] or end < newInterval[1]) && (ans[1] == 0 )){
                ans = { min(ans[0],start),newInterval[1]}; ;
                cout<<"new:"<<ans[0]<<","<<ans[1]<<endl;
            }
        }
        // cout<<"\nans:"<<ans[0]<<","<<ans[1]<<endl;
        for( auto &interval:intervals){
            if( interval[0] < ans[0] or interval[1] > ans[1] )
                merged.push_back(interval);
            if( interval[1] == ans[1] or interval[1]> ans[1] or intervals[intervals.size()-1][1]<ans[1] and ans[1] != -1){
                merged.push_back(ans);
                ans[1] = ans[0] = -1;
            }   
        }
        
    sort(merged.begin(), merged.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    });
        return merged;
    }
};
int main(){
    vector<vector<int>>intervals = {{1,5}};
    // {{1,2},{3,5},{6,7},{8,10},{12,16}} {{1,5}}
    vector<int>newInterval = {2,7};
    vector<vector<int>> ans;
    Solution obj;
    ans = obj.insert(intervals,newInterval);
    for( auto interval:ans){
        cout<<interval[0]<<","<<interval[1]<<endl;
    }
}