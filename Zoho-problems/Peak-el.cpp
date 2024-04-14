#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMax( vector<vector<int>> &arr, int rows, int mid ){
        int inx = -1, maxVal = INT_MIN;
        for( int i=0;i<rows;i++){
            if( arr[i][mid]>maxVal){
                maxVal = arr[i][mid];
                inx = i;
            }
        }
        return inx;
    }
    pair<int,int> find2D( vector<vector<int>> &arr ){
        int rows = arr.size(), cols = arr[0].size();
        int low =0,high = cols-1;
        while( low<= high){
            int mid = ( low+high) /2;
            int maxRow = findMax(arr, rows, mid);
            int left = mid-1>=0 ? arr[maxRow][mid-1]:-1;
            int right = mid+1<cols ? arr[maxRow][mid+1]:-1;
            if( arr[maxRow][mid]>left && arr[maxRow][mid]>right){
                return {maxRow,mid};
            }else if( arr[maxRow][mid]<left ){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return {-1,-1}; 
    }
};
int main(){
    vector<vector<int>> arr = {{4,5},{1,3}};
    Solution obj;
    pair<int,int> ans = obj.find2D(arr);
    cout<<"\nThe max el is at:"<<ans.first<<","<<ans.second;
}