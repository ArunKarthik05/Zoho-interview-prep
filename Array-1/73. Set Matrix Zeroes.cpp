#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> values;
        for( int i=0;i<matrix.size();i++){
            for( int j=0;j<matrix[0].size();j++){
                if( matrix[i][j] == 0)
                    values.push_back({i,j});
            }
        }

        for( auto &[row,col]:values ){
            for( int j=0;j<matrix[0].size();j++){
                matrix[row][j] = 0;
            }
            for( int i=0;i<matrix.size();i++){
                matrix[i][col] = 0;
            }
        }
    }
};
int main(){
    vector<vector<int>> matrix ={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution obj;
    obj.setZeroes(matrix);
    for( auto &row:matrix){
        for( auto &el:row){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}