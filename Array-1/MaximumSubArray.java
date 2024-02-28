import java.util.Scanner;

public class MaximumSubArray {
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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println(new Solution().maxSubArray(arr));

    }
}
