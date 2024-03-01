import java.util.Scanner;

public class PowXN {
    static class Solution {
        public double myPow(double x, int n) {
            double ans = 1;
            long N = n;
            if(N < 0){
                N = N*-1;
            }
            while(N > 0){
                if(N % 2 == 1){
                    ans = ans * x;
                    N = N-1;
                }
                else{
                    x = x * x;
                    N = N/2;
                }
            }
            if(n < 0){
                ans = 1 / ans;
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        int n = input.nextInt();
        System.out.println(new Solution().myPow(x,n));
    }
}
