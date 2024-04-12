#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        int value = 1;
        unordered_map<char,int> rank;
        for( auto ch:order){
            rank[ch] = value++;
        }
        for( int i=0;i<s.size()-1;i++){
            int j = i+ 1;
            while( rank[s[j]]<rank[s[j-1]] and j>0){
                cout<<"Cur str:"<<s<<endl;
                cout<<"swapping:"<<s[j]<<" and "<<s[j-1]<<endl;
                swap( s[j], s[j-1] );
                j--;
            }
        }
        return s;
    }
};
int main(){
    string  order = "cba", s = "abcfcd" ;
    Solution obj;
    obj.customSortString(order,s);
}