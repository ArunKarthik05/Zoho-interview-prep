import java.util.*;

public class MajorityElement2 {
    static class Solution {
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
            List<Integer> ans = new ArrayList<>();
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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        List <Integer> ans = new Solution().majorityElement(arr);
        for(int i: ans){
            System.out.print(arr[i] + " ");
        }
    }
}
