import java.util.Scanner;

public class UniquePaths {
    static class Solution {


        // Recursion Memoization
        int paths (int m, int n, int x, int y, int [][] dp){
            if(x == m || y == n){
                return 0;
            }
            if(x == m-1 && y == n-1){
                return 1;
            }
            if(dp[x][y] != -1){
                return dp[x][y];
            }
            int right = 0, down = 0;
            right += paths(m,n,x,y+1,dp);
            down  += paths(m,n,x+1,y,dp);
            return dp[x][y] = right + down;
        }

        // Tabulation
        int uPaths(int m, int n){
            int [][]dp = new int [m][n];
            for(int i = 0; i < m; i++){
                dp[i][n-1] = 1;
            }
            for(int i = 0; i < n; i++){
                dp[m-1][i] = 1;
            }
            for(int i = m-2; i >= 0; i--){
                for(int j = n-2; j >= 0; j--){
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
                }
            }

            return dp[0][0];
        }

        // Tabulation Space Optimized
        int uPaths1(int m, int n){
            int [][]dp = new int[2][n];
            for(int i = 0; i < n; i++){
                dp[0][i] = 1;
            }
            dp[1][0] =1;
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    dp[i & 1][j] = dp[(i-1)&1][j] + dp[i&1][j-1];
                }
            }
            return dp[(m-1)&1][n-1];
        }

        // Maths
        public int uniquePaths(int m, int n) {
            long ans = 1;
            for(int i = m+n-2, j = 1; i >= Math.max(m,n); i--,j++)
                ans = (ans*i)/j;
            return (int)ans;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();
        System.out.println(new Solution().uniquePaths(m,n));
    }
}
