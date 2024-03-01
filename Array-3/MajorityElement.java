import java.util.Arrays;
import java.util.Scanner;

public class MajorityElement {
    static class Solution {
        public int majorityElement(int[] nums) {
            int ans = nums[0], count = 0;
            for(int i = 0; i < nums.length; i++){
                if(count == 0){
                    ans = nums[i];
                }
                if(nums[i] == ans)
                    count++;
                else
                    count--;
            }
            return ans;
        }

        public int majorityElement1(int[] nums) {
            Arrays.sort(nums);
            return nums[nums.length/2];
        }

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println(new Solution().majorityElement(arr));
    }
}
