#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stoi(string s){
        int ans =0;
        bool isPos = true;
        for(int i=0;i<s.size();i++){
            if( s[i]== ' ')  continue;
            if( s[i] == '-' ){
                isPos = false;
                continue;
            }
            if( s[i]-48 <= 9){
                ans *= 10;
                ans += s[i] -48;
            }
        }
         if(isPos) {
            if(ans > INT_MAX) return INT_MAX;
        } else {
            if(-ans < INT_MIN) return INT_MIN;
        }
        return isPos ? ans: -ans;
    }
};
int main(){
    string s = "words and 098";
    Solution obj;
    int ans = obj.stoi(s);
    cout<<"\nAns:"<<ans;
}