#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string charCount( string s){
        string ans = "";
        vector<char> order;
        unordered_map<int,int> c;
        for( auto ch:s){
            c[ch]++;
            if( find(order.begin(),order.end(),ch)==order.end())
                order.push_back(ch);
        }
        for( auto ch:order){
            // cout<<"\ncount:"<<c[ch];
            ans += to_string(c[ch]);
            ans += ch;
        }
        return ans;
    }
};
int main(){
    string str= "dabbdda";
    Solution obj;
    string str2 = obj.charCount(str);
    cout<<str2;
}