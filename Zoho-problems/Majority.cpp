#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int> &arr) {
        vector<int> ans;
        int size = arr.size();
        unordered_map<int, int> count;
        unordered_map<int, int> order;

        for (int i = 0; i < size; i++) {
            count[arr[i]]++;
            if (order.find(arr[i]) == order.end())
                order[arr[i]] = i;
        }

        for (auto &[el, cnt] : count) {
            if (cnt > floor(size / 3)) {
                ans.push_back(el);
            }
        }
        
        vector<int> ans2;
        if( ans.size()>=2 && order[ans[0]]> order[ans[1]]  ){
            // cout<<order[ans[0]]<<","<<order[ans[1]];
            ans2.push_back( ans[1]);
            ans2.push_back( ans[0]);
        }   
            
        return ans.size()==2 ? ans2 : ans;
        // return ans;
    }
};

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 2};
    Solution obj;
    vector<int> ans = obj.findMajority(arr);
    cout << "Ans: ";
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
