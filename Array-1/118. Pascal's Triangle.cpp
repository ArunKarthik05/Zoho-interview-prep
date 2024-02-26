#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
      vector<vector<int>> generate(int numRows){
        vector<vector<int>> ans(numRows);
        for( int i=0;i<numRows;i++){
            for( int col=0;col<=i;col++){
                if( col == 0 or col==i ) ans[i].push_back(1);
                else{
                    int value = ans[i-1][col]+ans[i-1][col-1];
                    ans[i].push_back(value);
                }
            }
        }
        return ans;
      }
};
int main(){
    Solution obj;
    vector<vector<int>> ans = obj.generate(4);
    for(auto &row:ans){
        for( auto &el:row){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}