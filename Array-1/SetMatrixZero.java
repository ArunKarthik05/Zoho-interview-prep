import java.util.Scanner;

public class SetMatrixZero{

    static class Solution{
        public void setZeroes(int [][] matrix){
            int m = matrix.length;
            int n = matrix[0].length;
            boolean row = false, col = false;
            for(int i = 0; i < m; i++){
                if(matrix[i][0] == 0){
                    row = true;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                if(matrix[0][i] == 0){
                    col = true;
                    break;
                }
            }
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }

            if(row){
                for(int [] i: matrix){
                    i[0] = 0;
                }
            }

            if(col){
                for(int i = 0; i < n; i++){
                    matrix[0][i] = 0;
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
        new Solution().setZeroes(matrix);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.println(matrix[i][j]+ " ");
            }
            System.out.println();
        }
    }
}