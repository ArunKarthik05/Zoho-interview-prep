# 1.Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

### Example 1:
**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br>
**Output:** true

### Example 2:
**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13<br>
**Output:** false

<pre>
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int low = 0, high = m*n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            int i = mid/n, j = mid%n;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
}
</pre>

#
# 2.Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

### Example 1:
**Input:** x = 2.00000, n = 10<br>
**Output:** 1024.00000<br>

### Example 2:
**Input:** x = 2.10000, n = 3<br>
**Output:** 9.26100<br>

### Example 3:
**Input:** x = 2.00000, n = -2<br>
**Output:** 0.25000<br>
**Explanation:** 2-2 = 1/22 = 1/4 = 0.25

<pre>
class Solution {
    public double myPow(double x, int n) {
        double ans = 1;
        long N = n;
        if(N < 0){
            N = N*-1;
        }
        while(N > 0){
            if(N % 2 == 1){
                ans = ans * x;
                N = N-1;
            }
            else{
                x = x * x;
                N = N/2;
            }
        }
        if(n < 0){
            ans = 1 / ans;
        }
        return ans;
    }
}
</pre>

#
# 3.Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:<br>
**Input:** nums = [3,2,3]<br>
**Output:** 3

Example 2:<br>
**Input:** nums = [2,2,1,1,1,2,2]<br>
**Output:** 2

<pre>
class Solution {
    public int majorityElement(int[] nums) {
        int ans = nums[0], count = 0;
        for(int i = 0; i < nums.length; i++){
            if(count == 0) ans = nums[i];
            if(nums[i] == ans) count++;
            else count--;
        }
        return ans;
    }
}
</pre>

#
# 4.Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

### Example 1:<br>
**Input:** nums = [3,2,3]<br>
**Output:** [3]

### Example 2:<br>
**Input:** nums = [1]<br>
**Output:** [1]

### Example 3:<br>
**Input:** nums = [1,2]<br>
**Output:** [1,2]

<pre>
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1 = 0, cnt2 = 0, n = nums.length;
        int el1 = Integer.MIN_VALUE+1, el2 = Integer.MIN_VALUE+1;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                el2 = nums[i];
                cnt2++;
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }
        List <Integer> ans = new ArrayList<>();
        if(el2 > el1){
            int temp = el2;
            el2 = el1;
            el1 = temp;
            temp = cnt2;
            cnt2 = cnt1;
            cnt1 = temp; 
        }

        if(cnt1 > (n/3))
            ans.add(el1);
        if(cnt2 > n/3)
            ans.add(el2);
        return ans;
    }
}
</pre>