import java.util.Scanner;

public class MergeSortedArray {
    static class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
            int i = m-1, j = n-1, t = m+n-1;
            while(j >= 0){
                if(i >= 0 && nums1[i] > nums2[j])
                    nums1[t--] = nums1[i--];
                else
                    nums1[t--] = nums2[j--];
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();
        int [] nums1 = new int[m];
        int [] nums2 = new int[n];
        for (int i = 0; i < m; i++) {
            nums1[i] = input.nextInt();
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = input.nextInt();
        }
        new Solution().merge(nums1,m,nums2,n);
        for (int i = 0; i < m; i++) {
            System.out.print(nums1[i]+" ");
        }
    }
}
