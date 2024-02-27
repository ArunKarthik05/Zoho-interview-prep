#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for( int i=0;i<rows;i++){
            for( int j=0;j<=i;j++){
                swap( matrix[i][j],matrix[j][i]);
            }
        }
        cout<<"After Transpose:"<<endl;
        for( auto &row:matrix){
        for( auto &el:row){
            cout<<el<<" ";
        }
        cout<<endl;
        }
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void display( vector<vector<int>>& matrix ){
        for( auto &row:matrix){
        for( auto &el:row){
            cout<<el<<" ";
        }
        cout<<endl;
        }
    }
};
int main(){
    Solution obj;
    vector<vector<int>> matrix = {
        // {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}
        {1,2,3},{4,5,6},{7,8,9}
    };
    cout<<"Initial"<<endl;
    obj.display(matrix);
    obj.rotate(matrix);
    cout<<"Final"<<endl;
    obj.display(matrix);
}
/*
Logic 
Tranpose the matrix-Interchange rows and cols
    1 2 3    
    4 5 6
    7 8 9
<------------>
    1 4 7 
    2 5 8
    3 6 9
Now inter-change the cols
    7 4 1
    8 5 2
    9 6 3
*/