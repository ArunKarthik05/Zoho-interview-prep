import java.util.Scanner;

public class ReversePairs {
    static class Solution {
        int count  = 0;

        public int reversePairs(int[] nums) {
            if(nums.length < 2) return 0;
            return mergeSort(nums,0,nums.length-1);
        }


        int mergeSort(int [] arr, int l, int r){
            if(l >= r)
                return 0;
            int m = (l + r) / 2;
            mergeSort(arr,l, m);
            mergeSort(arr, m+1, r);

            count += merge(arr,l,m,r);
            return count;
        }

        private int merge(int[] arr, int l, int m, int r) {
            int n1 = m-l+1, n2 = r-m;
            int [] lArr = new int [n1];
            int [] rArr = new int [n2];
            for (int i = 0; i < n1; i++) {
                lArr[i] = arr[l+i];
            }
            for (int i = 0; i < n2; i++) {
                rArr[i] = arr[m+1+i];
            }

            int count = 0;

            for (int i = 0, j = 0; i < n1; ) {
                if(j < n2 && lArr[i] > (2 * (long)rArr[j])){
                    j++;
                }
                else {
                    count += j;
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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int [n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println(new Solution().reversePairs(arr));
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
