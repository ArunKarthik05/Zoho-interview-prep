#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void reverseWord(string &s,int inx,string &ans){
        if( inx <= 0)   
            return;
        string word = "";
        if( inx!= s.size()-1) ans += ' ';
        while( s[inx]!= ' '){
            word += s[inx];
            cout<<"\nWord:"<<word;
            inx--;
        }
        reverse(word.begin(),word.end());
        ans += word;
        reverseWord( s, inx-1,ans);
    }
};
int main(){
    string s =" This is a word";
    string ans = "";
    Solution obj;
    obj.reverseWord(s,s.size()-1,ans);
    cout<<"\n"<<ans;
}