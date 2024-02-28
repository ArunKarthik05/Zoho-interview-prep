import java.util.Scanner;

public class BuySellStock {
    static class Solution {
        public int maxProfit(int[] prices) {
            int min = prices[0];
            int max = 0;
            for (int i = 0; i < prices.length; i++) {
                min = Math.min(min, prices[i]);
                max = Math.max(max, prices[i] - min);
            }
            return max;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        System.out.println(new Solution().maxProfit(arr));
    }
}
