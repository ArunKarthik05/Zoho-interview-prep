#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(int row,int col,vector<vector<int>> &image, vector<vector<int>> &vis, int newCol,vector<int> &dx, vector<int> &dy){
        stack<pair<int,int>> s;
        int rows = image.size(), cols= image[0].size();
        int curColor = image[row][col];
        image[row][col] = newCol;
        vis[row][col] =1;
        s.push({row,col});

        while( !s.empty()){
            auto [curRow,curCol] = s.top();
            // cout<<curRow<<curCol<<endl;
            s.pop();
            image[curRow][curCol] = newCol;

            for( int i=0;i<4;i++){
                int nextRow = curRow + dx[i];
                int nextCol = curCol + dy[i];

                if( nextRow>=0 && nextRow<rows && nextCol>=0 && nextCol<cols && !vis[nextRow][nextCol] && image[nextRow][nextCol] == curColor){
                    dfs( nextRow,nextCol,image,vis,newCol,dx,dy);
                }
            }
        }
    }
};
int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int rows = image.size(), cols= image[0].size();
    vector<vector<int>> vis(rows,vector<int>(cols,0));
    int newColor = 2 ,startRow= 1, startCol =1;
    
    vector<int> dx = {1, 0, -1,  0};
    vector<int> dy = {0, 1,  0, -1};

    Solution s;
    s.dfs(startRow,startCol,image,vis,newColor,dx,dy);
    
    for( auto row:image){
        for( auto el:row){
            cout<<el<<' ';
        }
        cout<<endl;
    }
}