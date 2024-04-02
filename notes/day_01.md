```java
public class Demo {

    void quickSort(int [] arr, int low, int high){
        if(high <= low)
            return;
        int pIndex = place(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);

    }

    int place(int []arr, int low, int high){
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j){
            while (arr[i] <= pivot && i < high) i++;
            while (arr[j] > pivot && j > low) j--;
            if (i < j) swap(arr,i,j);
        }
        swap(arr,low,j);
        return j;
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void mergeSort(int []arr, int low, int high){
        if(high <= low)
            return;
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }

    private void merge(int[] arr, int low, int mid, int high) {
        int n1 = mid-low+1, n2 = high-mid;
        int [] left = new int[n1];
        int [] right = new int[n2];
        for (int i = 0; i < n1; i++){
            left[i] = arr[low+i];
        }
        for (int i = 0; i < n2; i++){
            right[i] = arr[mid+1+i];
        }
        int i,j,t;
        for (i = 0, j = 0, t = low; i < n1 && j < n2; t++) {
            if (left[i] < right[j]){
                arr[t] = left[i];
                i++;
            }
            else {
                arr[t] = right[j];
                j++;
            }
        }
        while (i < n1){
            arr[t++] = left[i++];
        }
        while (j < n2){
            arr[t++] = right[j++];
        }

    }
}
```

# 1.Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

### Example 1:

**Input:** matrix = [[1,1,1],[1,0,1],[1,1,1]]<br>
**Output:** [[1,0,1],[0,0,0],[1,0,1]]

### Example 2:

**Input:** matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]<br>
**Output:** [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```java
static class Solution{
    public void setZeroes(int [][] matrix){
        int m = matrix.length;
        int n = matrix[0].length;
        boolean row = false, col = false;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                row = true;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                col = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(int [] i: matrix){
                i[0] = 0;
            }
        }

        if(col){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
    }
}
```
#
# 2.Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

### Example 1:

**Input:** numRows = 5<br>
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

### Example 2:

**Input:** numRows = 1<br>
**Output:** [[1]]

```java
static class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> arr = new ArrayList<>();
        arr.add(new ArrayList<>());
        arr.get(0).add(1);

        for (int i = 1; i < n; i++) {
            arr.add(new ArrayList<>());
            for (int j = 0; j < i + 1; j++) {
                int val = 1;
                if (j != 0 && j != i) {
                    val = arr.get(i - 1).get(j - 1) + arr.get(i - 1).get(j);
                }
                arr.get(i).add(val);
            }

        }
        return arr;
    }
}
```

#
# 3.Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]. <br>
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].<br>
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].<br>
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.<br>
Given an array of integers nums, find the next permutation of nums.<br>

The replacement must be in place and use only constant extra memory.

 

### Example 1:

**Input:** nums = [1,2,3]<br>
**Output:** [1,3,2]<br>
### Example 2:

**Input:** nums = [3,2,1]<br>
**Output:** [1,2,3]
### Example 3:

**Input:** nums = [1,1,5]<br>
**Output:** [1,5,1]
```java
static class Solution {
    public void nextPermutation(int[] nums) {
        int index = -1, n = nums.length;
        if(n == 1){
            return;
        }
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index != -1){
            for(int i = n-1; i > index; i--){
                if(nums[i] > nums[index]){
                    int temp = nums[index];
                    nums[index] = nums[i];
                    nums[i] = temp;
                    break;
                }
            }
        }

        for(int i = index+1, j = n-1; i < j; i++,j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
```

#
# 4.Maximum Subarray

Given an integer array nums, find the 
subarray with the largest sum, and return its sum.

### Example 1:

**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]<br>
**Output:** 6<br>
**Explanation:** The subarray [4,-1,2,1] has the largest sum 6.
### Example 2:

**Input:** nums = [1]<br>
**Output:** 1<br>
**Explanation:** The subarray [1] has the largest sum 1.
### Example 3:

**Input:** nums = [5,4,-1,7,8]<br>
**Output:** 23<br>
**Explanation:** The subarray [5,4,-1,7,8] has the largest sum 23.

```java
static class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE + 1;
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
}
```
#
# 5.Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


### Example 1:

**Input:** nums = [2,0,2,1,1,0]<br>
**Output:** [0,0,1,1,2,2]
### Example 2:

**Input:** nums = [2,0,1]<br>
**Output:** [0,1,2]
```java
static class Solution {
    public void sortColors(int[] nums) {
        int start= 0, last = nums.length-1;
        for(int i = 0; i <= last; ){
            if(nums[i] == 0){
                nums[i] = nums[start];
                nums[start++] = 0;
            }
            if(nums[i] == 2){
                nums[i] = nums[last];
                nums[last--] = 2;
                continue;
            }
            i++;
        }
    }
}
```
#
# 6.Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Example 1:

**Input:** prices = [7,1,5,3,6,4] <br>
**Output:** 5 <br>
**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. <br>
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

### Example 2:

**Input:** prices = [7,6,4,3,1] <br>
**Output:** 0 <br>
**Explanation:** In this case, no transactions are done and the max profit = 0.

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = Integer.MIN_VALUE + 1;
        int minValue = Integer.MAX_VALUE - 1;
        for(int i = 0; i < prices.length; i++){
            minValue = Math.min(minValue, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i]-minValue);
        }
        return maxProfit;
    }
}
```
