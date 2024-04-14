#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findSum(vector<vector<int>> &arr){
        vector<vector<int>> ans;
        int rows = arr.size(), cols = arr[0].size();
        for( int i=0;i<rows;i++){
            vector<int>rowSum;
            for( int j=0;j<cols;j++){
                if( i+1<rows && j+1<cols){
                    int sum = calc({i,j},{i+2,j+2},arr);
                    rowSum.push_back(sum);
                }
            }
                ans.push_back(rowSum);
        }   
        return ans;
    }
    int calc( pair<int,int>start, pair<int,int>end, vector<vector<int>> &arr){
        int sum =0;
        cout<<"\nThe ranges are row:"<<start.first<<","<<start.second<<" COl:"<<end.first<<","<<end.second;
        for( int i=start.first;i<end.first;i++){
            for( int j=start.second;j<end.second;j++){
                sum += arr[i][j];
                cout<<"\ncursum:"<<sum;
            }
        }
        cout<<"\nThe sum is:"<<sum;
        return sum;
    }
};
int main(){
    vector<vector<int>> arr = { {1,2,3}, {4,5,6}, {7,8,9}};
    Solution obj;
    vector<vector<int>> ans = obj.findSum(arr);
    cout<<"\nAns:"<<endl;
    for( auto row:ans){ 
        for( auto el:row){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}