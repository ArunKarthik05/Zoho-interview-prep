#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int left = 0, right = 0;
        vector<int> ans;
        while (left < nums1.size() && right < nums2.size()) {
            if (nums1[left] == nums2[right]) {
                ans.push_back(nums1[left]);
                left++;
                right++;
            } else if (nums1[left] < nums2[right]) {
                left++;
            } else {
                right++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 4, 5};
    vector<int> nums2 = {7, 9, 3, 4, 4, 8};
    Solution obj;
    vector<int> result = obj.intersection(nums1, nums2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
