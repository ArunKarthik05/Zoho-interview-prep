import java.util.Scanner;

public class CountInversions {

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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = 6;//input.nextInt();
        long [] arr = {3, 5, 2, 1, 7, 4};// new int [n];
//        for (int i = 0; i < n; i++) {
//            arr[i] = input.nextInt();
//        }
        new Solution();
        System.out.println(Solution.getInversions(arr,n));
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
