import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PascalsTriangle {
    static class Solution {
        public List<List<Integer>> generate(int n) {
            List<List<Integer>> arr = new ArrayList<>();
            arr.add(new ArrayList<Integer>());
            arr.get(0).add(1);
            System.out.println(1);

            for (int i = 1; i < n; i++) {
                arr.add(new ArrayList<Integer>());
                for (int j = 0; j < i + 1; j++) {
                    int val = 1;
                    if (j != 0 && j != i) {
                        val = arr.get(i - 1).get(j - 1) + arr.get(i - 1).get(j);
                    }
                    System.out.print(val + " ");
                    arr.get(i).add(val);
                }
                System.out.println();

            }
            return arr;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        List<List<Integer>> ans = new Solution().generate(n);
        // for(ArrayList<Integer> i:ans){
        // for(int j: i){
        // System.out.println(j);
        // }
        // }
    }
}
