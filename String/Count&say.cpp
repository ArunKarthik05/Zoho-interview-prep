#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string CountandSay(int count){
        string ans = "1";
        while( count>1){
            int itr =0;
            string next = "";
            while( itr<ans.size() ){
                int count = 1;
                while(itr < ans.size()-1 &&  ans[itr] == ans[itr+1] ){
                    count++;
                    itr++;
                }
                cout<<"\nCount:"<<count<<" Num:"<<ans[itr];
                next += to_string(count);
                next += ans[itr];
                itr++;
            }                
            cout<<"\nNext:"<<next;
            ans = next;
            count--;
        }
        return ans;
    }
};
int main(){
    Solution obj;
    obj.CountandSay(4);
}
