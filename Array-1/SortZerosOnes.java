import java.util.Scanner;

public class SortZerosOnes {
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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        new Solution().sortColors(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
