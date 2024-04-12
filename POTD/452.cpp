#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort( points.begin(), points.end(), [](const vector<int>&a, vector<int>&b){
            return a[0]< b[0];
        });
        int ans = 1;
        pair<int,int> range = {points[0][0], points[0][1]};
        for( auto &point:points){
            int start = point[0];
            int end = point[1];
            cout<<"Point"<<start<<","<<end<<endl;
            if( start<= range.second ){
                range.first = max( range.first, start);
                range.second = min( range.second, end);
                cout<<range.first<<","<<range.second<<endl;
            }else{
                ans ++;
                cout<<"ans:"<<ans<<endl;
                range = { start, end};
                cout<<range.first<<","<<range.second<<endl;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>>points = {{1,2}, {3,4}, {5,6}, {7,8} };
    //{10,16}, {2,8}, {1,6}, {7,12}
    //
    //{1,2}, {2,3}, {4,5}, {5,6}
    Solution obj;
    int ans = obj.findMinArrowShots(points);
    cout<<"\nAns :"<<ans;
}