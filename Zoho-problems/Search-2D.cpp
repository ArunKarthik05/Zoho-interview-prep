#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> Search( vector<vector<int>> &arr, int target ){
        int rows = arr.size(), cols = arr[0].size();
        int low =0, high = rows*cols-1;
        while( low<= high){
            cout<<"Searching between "<<low<<" and "<<high<<endl;
            int mid = (low+high)/2;
            int row = mid/ cols;
            int col = mid % cols;
            if( arr[row][col] < target)  {
                low = mid+1;
            }
            else if( arr[row][col] > target )   high = mid-1;
            else if( arr[row][col] == target ) return {row,col};
        }
        return {-1,-1};
    }
};
int main(){
    vector<vector<int>> arr = { {1,3,5,7}, {10,11,16,20},{23,30,34,60} };
    int target = 60;
    Solution obj;
    pair<int,int> ans = obj.Search(arr, target);
    if( ans.first !=-1 and ans.second!=-1)
        cout<<"El found at:"<<ans.first<<"th row &"<<ans.second<<"th col"<<endl;
    else 
        cout<<"El not found"<<endl;
}