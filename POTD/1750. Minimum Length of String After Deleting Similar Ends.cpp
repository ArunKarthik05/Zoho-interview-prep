#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumLength(string s) {
        int size = s.size();
        if( size<3) return size;
        int left = 0, right =size-1;
        while( right>=left and s[left]==s[right] ){
            cout<<"right:"<<right<<endl;
            cout<<"left:"<<left<<endl;
            cout<<s[right]<<"=="<<s[left]<<endl;
            char curChar = s[left];
            while( s[left] == curChar and left<=right ){
                cout<<"Comapare:"<<s[left]<<","<<s[left+1]<<endl;
                left++;
            }
            while( s[right] == curChar and left<= right){                
                cout<<"Comapare:"<<s[right]<<","<<s[right-1]<<endl;
                right--;
            }
            left++;
            right--;
        }
        cout<<"FInal:"<<s[right]<<","<<s[left];
        cout<<"FInal:"<<right<<","<<left;
        return right-left+1>0 ? right-left+1 : size;
    }
};
int main(){
    string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
    Solution obj;
    int ans = obj.minimumLength(s);
    cout<<"Ans:"<<ans;
}