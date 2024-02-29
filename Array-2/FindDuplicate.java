import java.util.Scanner;

public class FindDuplicate {
    static class Solution {

//        Without Replacement - Fast
        public int findDuplicate1(int[] nums) {
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

//With Replacement - Faster
        public int findDuplicate2(int[] nums) {
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

//         Using Extra Space - fastest
        public int findDuplicate3(int[] nums) {
            boolean [] arr= new boolean[nums.length];
            for(int num:nums)
            {
                if(arr[num])
                {
                    return num;
                }
                else
                {
                    arr[num]=true;
                }
            }
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.print(new Solution().findDuplicate1(arr));

    }
}
