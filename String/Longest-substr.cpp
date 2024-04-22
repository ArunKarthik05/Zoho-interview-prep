#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ans = "";
        set<char>f;
        int left = 0, right = 0, maxlen = 0;
        while (right < s.size()) {
            char cur = s[right];
            auto it = f.find(cur);
            if (it != f.end()) {
                f.erase(left++);
            }else{
                f.insert(s[right++]);
                maxlen = max(maxlen, right - left + 1);
            }
 
        }
        return maxlen;
    }
};

int main() {
    string str = "pwwkew";
    Solution obj;
    int ans = obj.lengthOfLongestSubstring(str);
    cout <<"\nAns:"<<ans;
    return 0;
}