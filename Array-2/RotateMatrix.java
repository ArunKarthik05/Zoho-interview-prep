import java.util.Scanner;

public class RotateMatrix {
    static class Solution {
        public void rotate(int[][] matrix) {
            int n = matrix.length;
            for (int i = 0; i < n-1; i++) {
                for(int j = i+1; j < n; j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
            for(int [] arr: matrix){
                for(int i = 0, j = n-1; i < j; i++,j--){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
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
        new Solution().rotate(matrix);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.println(matrix[i][j]+ " ");
            }
            System.out.println();
        }
    }
}
