import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MergeIntervals {
    static class Solution {
        public int[][] merge(int[][] intervals) {
            if(intervals.length <= 1)
                return intervals;
            quickSort(intervals, 0, intervals.length - 1);
            List <int []> ans = new ArrayList<>();
            ans.add(intervals[0]);
            int start = intervals[0][0], end = intervals[0][1];
            for(int i = 1; i < intervals.length; i++){
                int cstart = intervals[i][0], cend = intervals[i][1];
                if(cstart <= end){
                    if(cend > end){
                        ans.set(ans.size()-1, new int[]{start,cend});
                        end = cend;
                    }
                    continue;
                }
                start = cstart;
                end = cend;
                ans.add(intervals[i]);
            }

            return ans.toArray(new int[ans.size()][2]);

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

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [][] matrix = new int [n][2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                matrix[i][j] = input.nextInt();
            }
        }
        int [][] ans = new Solution().merge(matrix);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                System.out.println(ans[i][j]+ " ");
            }
            System.out.println();
        }
    }
}
