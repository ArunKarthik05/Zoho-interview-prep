#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<char,int>> count;
        int ans = 0;
        for (auto &task : tasks) {
            bool found = false;
            for (auto &item : count) {
                if (item.first == task) {
                    item.second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                count.push_back({task, 1});
            }
        }
        sort(count.begin(), count.end(), [](const pair<char,int>&a, const pair<char,int>&b){
            return a.first < b.first;
        });
        while(count.size()){
            
        }
        for( auto &task:count){
            cout<<task.first<<","<<task.second<<endl;
        }
        return ans;
    }
};
int main(){
    vector<char> tasks = { 'A','A','A','B','B','B' };
    int n =2;
    Solution obj;
    cout<<obj.leastInterval(tasks,n);
}