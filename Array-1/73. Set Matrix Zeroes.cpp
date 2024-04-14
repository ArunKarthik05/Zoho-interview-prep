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
    vector<vector<int>> Optimize( vector<vector<int>>& matrix ){
        int zeroCol = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        for( int i=0;i<rows;i++){
            if( matrix[i][0] == 0){
                zeroCol=0;
                break;
            }
        }
        for( int i=0;i<cols;i++){
            if( matrix[0][cols] == 0){
                matrix[0][0]=0;
                break;
            }
        }
        for( int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if( matrix[i][j] == 0){
                    matrix[0][j] = 0; //0th row
                    matrix[i][0] = 0; //0th col
                }
            }
        }
        for( int j=0;j<rows;j++){
            if( zeroCol ){
                matrix[rows][0] =0;
            }
        }
        for( int j=0;j<rows;j++){
            if( matrix[0][0] ==0 ){
                matrix[j][0] =0;
            }
        }
        for( int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){   
                if( matrix[0][j] == 0 || matrix[i][0]==0){
                    matrix[i][j] =0;
                }   
            }
        }
        return matrix;
    } 
};
int main(){
    vector<vector<int>> matrix ={
        {1,1,2,1},
        {0,0,5,2},
        {1,3,0,5}
    };
    Solution obj;
    // obj.setZeroes(matrix);
    obj.Optimize(matrix);
    for( auto &row:matrix){
        for( auto &el:row){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}