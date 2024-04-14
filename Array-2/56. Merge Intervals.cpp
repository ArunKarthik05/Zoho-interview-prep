#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> lastInterval = result.back();
            if (intervals[i][0] > lastInterval[1])
            {
                result.push_back(intervals[i]);
            }
            else if (intervals[i][1] > lastInterval[1])
            {
                result.pop_back();
                lastInterval[1] = intervals[i][1];
                result.push_back(lastInterval);
            }
        }
        for( auto &row:result){
            for( auto &el:row){
                cout<<el<<" ";
            }
            cout<<endl;
        }
        return result;
    }
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr ) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
    }
};
int main(){
    vector<vector<int>>arr = {{1,3},{2,6},{8,10},{15,18}};
    Solution obj;
    // obj.merge(intervals);
    vector<vector<int>> ans = obj.mergeOverlappingIntervals(arr);
    for( auto interval:ans){
        cout<<"{"<<interval[0]<<","<<interval[1]<<"}"<<endl;
    }
}