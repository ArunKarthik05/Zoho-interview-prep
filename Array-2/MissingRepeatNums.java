import java.util.ArrayList;
import java.util.Scanner;

public class MissingRepeatNums {

    static class Solution {

        public static int[] missingAndRepeating(ArrayList<Integer> arr, int n) {
            // Write your code here
            long sum = 0, sumSq = 0;
            long N = n;
            long sn = (N*(N+1))/2, sn2 = (N*(N+1)*(2*N+1))/6;
            for(int i = 0; i < n; i++){
                sum += arr.get(i);
                sumSq += ((long) arr.get(i) *arr.get(i));
            }
            long  x, y;
            x = sum - sn;
            y = sumSq - sn2;
            y = y / x;
            int [] result = new int [2];
            result[1] = (int)((x+y)/2);
            result[0] = (int) (result[1] - x);
            return result ;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<Integer> arr = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            int x = input.nextInt();
            arr.add(x);
        }
        int [] pair = Solution.missingAndRepeating(arr,n);
        System.out.println("Missing  "+pair[0]);
        System.out.println("Repeated "+pair[1]);
    }
}
