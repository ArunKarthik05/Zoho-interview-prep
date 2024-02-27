import sde_sheet.Demo;

import java.util.Scanner;

public class SetMatrixZero {

    static class Solution {
        public void setZeroes(int[][] arr) {
            int m = arr.length, n = arr[0].length;
            boolean row = false, col = false;
            for (int i = 0; i < m; i++) {
                if (arr[i][0] == 0) {
                    row = true;
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (arr[0][i] == 0) {
                    col = true;
                    break;
                }
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (arr[i][j] == 0) {
                        arr[0][j] = 0;
                        arr[i][0] = 0;
                    }
                }
            }
            for (int i = 1; i < m; i++) {
                if (arr[i][0] == 0) {
                    for (int j = 1; j < n; j++) {
                        arr[i][j] = 0;
                    }
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (arr[0][i] == 0) {
                        if (arr[0][i] == 0 || arr[j][0] == 0)
                            arr[j][i] = 0;
                    }

                }
            }
            if (row) {
                for (int i = 0; i < m; i++)
                    arr[i][0] = 0;
            }
            if (col) {
                for (int i = 0; i < n; i++)
                    arr[0][i] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();
        int[][] arr = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = input.nextInt();
            }
        }
        new Solution().setZeroes(arr);
        for (int[] i : arr) {
            for (int j : i)
                System.out.print(j + " ");
            System.out.println();
        }
    }

}