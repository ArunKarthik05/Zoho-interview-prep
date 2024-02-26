#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSubArray(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ans = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution obj;
    cout << "ANS: " << obj.minSubArray(target, nums);
    return 0;
}
