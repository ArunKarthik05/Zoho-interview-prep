import java.util.Scanner;

public class NextPermutaion {
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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        new Solution().nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
