#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int romanToInt(string s) {
        int ans =0;
            unordered_map<char,int> values = {
                {'I',1},
                {'V',5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000},
            };
            for( int i=0;i<s.size();i++){
                cout<<"\nChar:"<<s[i];
                if( i-1>0 && values[s[i]]>values[s[i-1]] ){
                    ans += values[ s[i] ] - values [s[i-1]];
                    cout<<"\nAdded "<<values[ s[i] ] - values [s[i-1]];
                    ans -= values[s[i-1]];
                    cout<<"\nSubracted "<< values[s[i-1]];
                }else{
                    ans += values[ s[i]];
                }
                cout<<"\nEndVal:"<<ans;
            }
            return ans;
    }
};
int main(){
    string s = "MCMXCIV";
    // MCMXCIV
    Solution obj;
    int ans = obj.romanToInt(s);
    cout<<"\nAns:"<<ans;
}