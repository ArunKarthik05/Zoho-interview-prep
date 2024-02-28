#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    pair<int,int>find( vector<int> &array ){
        int count[256] = {0};

        pair<int,int> ans = {-1,-1};
        for( auto &el:array){
            count[el]++;
        }
        for (int i = 1; i < 256; ++i) {
            if (count[i] > 1) {
                std::cout << "Value " << i << " occurs " << count[i] << " times." << std::endl;
            }
            if(count[i] ==0 and ans.second == -1 ){
                cout<<"The missing no is:"<<i;
                ans.second = i;
            }
        }   
    }
};    
int main(){
    vector<int> array = {3,1,2,5,4,6,7,5};
    Solution obj;
    obj.find(array);
}