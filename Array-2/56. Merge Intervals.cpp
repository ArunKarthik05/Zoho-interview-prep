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
};
int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution obj;
    obj.merge(intervals);
}