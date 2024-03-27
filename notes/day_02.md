# 1.Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

### Example 1:.

**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]<br>
**Output:** [[7,4,1],[8,5,2],[9,6,3]]

### Example 2:

**Input:** matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]<br>
**Output:** [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

<pre>
static class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
}
</pre>

#

# 2.Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Example 1:

**Input:** intervals = [[1,3],[2,6],[8,10],[15,18]]<br>
**Output:** [[1,6],[8,10],[15,18]]<br>
**Explanation:** Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

### Example 2:

**Input:** intervals = [[1,4],[4,5]]<br>
**Output:** [[1,5]]<br>
**Explanation:** Intervals [1,4] and [4,5] are considered overlapping.

<pre>
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length <= 1){
            return intervals;
        }
        quickSort(intervals, 0, intervals.length - 1);
        List <int []> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for(int i = 0; i < intervals.length; i++){
            int [] last = ans.get(ans.size()-1);
            if(intervals[i][0] > last[1]){
                ans.add(intervals[i]);
            }
            else{
                last[1] = Math.max(last[1], intervals[i][1]);
            }
        }
        int[][] ansArr = new int[ans.size()][2];
        for (int i = 0; i < ans.size(); i++) {
            ansArr[i] = ans.get(i);
        }
        return ansArr;
    }
    private void quickSort(int[][] arr, int low, int high) {
        if (low >= high) return;

        int[] p = arr[high];

        int i = (low - 1);
        for (int j = low; j <= high; j++) {
            if (arr[j][0] < p[0]) {
                swap(arr, ++i, j);
            } else if (arr[j][0] == p[0] && arr[j][1] < p[1]) {
                swap(arr, ++i, j);
            }
        }
        swap(arr, ++i, high);

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }

    private void swap(int[][] arr, int x, int y) {
        if (x == y) return;
        int[] temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}
</pre>

#

# 3.Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

### Example 1:

**Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3<br>
**Output:** [1,2,2,3,5,6]<br>
**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].<br>
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.<br>

### Example 2:

**Input:** nums1 = [1], m = 1, nums2 = [], n = 0<br>
**Output:** [1]<br>
**Explanation:** The arrays we are merging are [1] and [].<br>
The result of the merge is [1].<br>

### Example 3:

**Input:** nums1 = [0], m = 0, nums2 = [1], n = 1<br>
**Output:** [1]<br>
**Explanation:** The arrays we are merging are [] and [1].
The result of the merge is [1].<br>
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

<pre>
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m-1, j = n-1, t = m+n-1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[t--] = nums1[i--];
            }
            else{
                nums1[t--] = nums2[j--];
            }
        }
    }
}
</pre>

#
# 4.Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 
### Example 1:
**Input:** nums = [1,3,4,2,2]<br>
**Output:** 2

### Example 2:
**Input:** nums = [3,1,3,4,2]<br>
**Output:** 3

### Example 3:
**Input:** nums = [3,3,3,3,3]<br>
**Output:** 3

<pre>
static class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(nums[slow] != nums[fast]);
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
}
</pre>


#
# 5.Find the repeating and missing numbers

**Problem Statement:** You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

### Example 1:###

**Input Format:** array[] = {3,1,2,5,3}<br>
**Result:** {3,4}<br>
**Explanation:** A = 3 , B = 4 <br>
Since 3 is appearing twice and 4 is missing

### Example 2:###

**Input Format:** array[] = {3,1,2,5,4,6,7,5}<br>
**Result:** {5,8}<br>
**Explanation:** A = 5 , B = 8 <br>
Since 5 is appearing twice and 8 is missing

<pre>

public class Solution {
    public static int[] missingAndRepeating(ArrayList<Integer> arr, int N) {
        long n = (long) N;
        long x = (n*(n+1))/2;
        long x2 = (n*(n+1)*(2*n+1))/6;
        long y = 0, y2 = 0;
        for(int i = 0; i < n; i++){
            y += arr.get(i);
            y2 += ((long) arr.get(i) *arr.get(i));
        }
        long xMinusY = x-y;
        long xsqMinusYsq = x2-y2;
        long xPlusY = xsqMinusYsq/xMinusY;
        long xValue = (xMinusY + xPlusY)/2;
        long yValue = (xMinusY - xPlusY)/2;
        int a = (int)(xValue), b = Math.abs((int)(yValue));
        int [] ans = {a,b}; 
        return ans;
    }
}
</pre>

#

# 6.Count inversions in an array

**Problem Statement:** Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Examples

### Example 1:

**Input Format:** N = 5, array[] = {1,2,3,4,5}<br>
**Result:** 0<br>
**Explanation:** we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

### Example 2:

**Input Format:** N = 5, array[] = {5,4,3,2,1}<br>
**Result:** 10<br>
**Explanation:** we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions and for reverse sorted array we will get maximum inversions and that is (n)\*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

### Example 3:

**Input Format:** N = 5, array[] = {5,3,2,1,4}<br>
**Result:** 7<br>
**Explanation:** There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.

<pre>
static class Solution {
    public static long getInversions(long arr[], int n) {
        // Write your code here.
        return new Solution().mergeSort(arr,0,n-1);
    }
    long count  = 0;

    long mergeSort(long [] arr, int l, int r){
        if(l >= r)
            return 0;
        int m = (l + r) / 2;
        mergeSort(arr,l, m);
        mergeSort(arr, m+1, r);

        count += merge(arr,l,m,r);
        return count;
    }

    private long merge(long[] arr, int l, int m, int r) {
        int n1 = m-l+1, n2 = r-m;
        long [] lArr = new long [n1];
        long [] rArr = new long [n2];
        for (int i = 0; i < n1; i++) {
            lArr[i] = arr[l+i];
        }
        for (int i = 0; i < n2; i++) {
            rArr[i] = arr[m+1+i];
        }

        long count = 0;
        for (int i = 0, j = 0; i < n1 && j < n2; ) {
            if(lArr[i] > rArr[j]){
                count += n1-i;
                j++;
            }
            else {
                i++;
            }
        }

        int i,j,t;
        for (i = 0, j = 0, t = l; i < n1 && j < n2; t++){
            if (lArr[i] < rArr[j]){
                arr[t] = lArr[i++];
            }
            else{
                arr[t] = rArr[j++];
            }
        }
        while (i < n1){
            arr[t++] = lArr[i++];
        }
        while (j < n2){
            arr[t++] = rArr[j++];
        }
        return count;
    }
}
</pre>
