import java.util.Scanner;

public class Search2dMatrix {
    static class Solution {

        // Best Solution O  (log (m*n))
        public boolean searchMatrix(int[][] matrix, int target) {
            int row = matrix.length, col = matrix[0].length;
            int l = 0, r = row*col-1;
            while(l <= r){
                int mid = (l+r)/2;
                int i = mid/col, j = mid%col;
                if(matrix[i][j] == target) return true;
                else if(matrix[i][j] < target) l = mid+1;
                else r = mid-1;
            }
            return false;
        }

        // Easy and Best  O(n+m)
        public boolean searchMatrix1(int[][] matrix, int target) {
            int i=0;
            int j=matrix[0].length-1;

            while(i<matrix.length && j>=0){
                if(matrix[i][j]==target)return true;
                else if(matrix[i][j]<target)i++;
                else j--;
            }

            return false;

            /*
            int row = matrix.length-1, col = 0;
            while(row >= 0 && col < matrix[0].length){
                if(matrix[row][col] == target) return true;
                else if(matrix[row][col] < target) col++;
                else row--;
            }
            return false;
             */
        }


        // Better Solution O (m*log n)
        public boolean searchMatrix2(int[][] matrix, int target) {
            int n = matrix[0].length;
            for(int [] arr : matrix){
                if(arr[0] <= target && arr[n-1] >= target){
                    if(arr[0] == target || arr[n-1] == target)
                        return true;
                    int low = 0, high = arr.length-1;
                    while(low < high){
                        int mid = (low+high)/2;
                        if(arr[mid] == target) return true;
                        else if(arr[mid] < target) low = mid+1;
                        else high = mid;
                    }
                    return false;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();
        int [][] matrix = new int [m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = input.nextInt();
            }
        }
        int target = input.nextInt();
        System.out.println(new Solution().searchMatrix(matrix,target));

    }
}
