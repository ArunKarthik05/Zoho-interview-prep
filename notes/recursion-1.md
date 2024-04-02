# 1.Subset Sums

Given a list arr of N integers, return sums of all subsets in it.

### Example 1:

#### Input:

N = 2<br>
arr[] = {2, 3}<br>

#### Output:<br>

0 2 3 5

**Explanation:**

- When no elements is taken then Sum = 0.
- When only 2 is taken then Sum = 2.
- When only 3 is taken then Sum = 3.
- When element 2 and 3 are taken then
- Sum = 2+3 = 5.

### Example 2:

#### Input:

N = 3<br>
arr = {5, 2, 1}<br>

#### Output:<br>

0 1 2 3 5 6 7 8

```java
class Solution{
    void allsums(ArrayList<Integer> arr, ArrayList<Integer> ans, int n, int sum, int i){
        if(i >= n){
            ans.add(sum);
            return ;
        }
        allsums(arr, ans, n, sum, i+1);
        allsums(arr, ans, n, sum+arr.get(i), i+1);
    }

    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int N){
        ArrayList <Integer> res = new ArrayList<>();
        allsums(arr, res, N, 0, 0);
        Collections.sort(res);
        return res;
    }
}
```

# 2.Subsets II

Given an integer array nums that may contain duplicates, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

```java
class Solution {

    public static void findSubsets(int ind, int[] nums, List<Integer> ds, List<List<Integer>> ansList) {
        ansList.add(new ArrayList<>(ds));
        for(int i = ind;i<nums.length;i++) {
            if(i!=ind && nums[i] == nums[i-1]) continue;
            ds.add(nums[i]);
            findSubsets(i+1, nums, ds, ansList);
            ds.remove(ds.size() - 1);
        }

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ansList = new ArrayList<>();
        findSubsets(0, nums, new ArrayList<>(), ansList);
        return ansList;
    }
}
```

# 3.Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

### Example 1:

**Input:** candidates = [2,3,6,7], target = 7<br>
**Output:** [[2,2,3],[7]]<br>
**Explanation:**
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

### Example 2:

**Input:** candidates = [2,3,5], target = 8<br>
**Output:** [[2,2,2,2],[2,3,3],[3,5]]<br>

### Example 3:

**Input:** candidates = [2], target = 1<br>
**Output:** []<br>

```java
class Solution {

    void helper(int[] candidates, List<List<Integer>> result, 
        List<Integer>arr, int target, int sum, int index){
            if(index == candidates.length){
                if(sum == target){
                    result.add(new ArrayList<>(arr));
                }
                return;
            }
            if(sum + candidates[index] <= target){
                sum += candidates[index];
                arr.add(candidates[index]);
                helper(candidates, result, arr, target, sum, index);
                arr.remove(arr.size()-1);
                sum -= candidates[index];
            }
            helper(candidates, result, arr, target, sum, index+1);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List <Integer> arr = new ArrayList<>();
        helper(candidates, result, arr, target, 0, 0);
        return result;
    }
}
```

# 4.Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

**Note:** The solution set must not contain duplicate combinations.

### Example 1:
**Input:** candidates = [10,1,2,7,6,1,5], target = 8<br>
**Output:** <br>
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

### Example 2:
**Input:** candidates = [2,5,2,1,2], target = 5<br>
**Output:** <br>
[
[1,2,2],
[5]
]

```java
class Solution {
    static void findCombinations(int ind, int[] arr, int target, List < List < Integer >> ans, List < Integer > ds) {
        if (target == 0) {
            ans.add(new ArrayList < > (ds));
            return;
        }

        for (int i = ind; i < arr.length; i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;

            ds.add(arr[i]);
            findCombinations(i + 1, arr, target - arr[i], ans, ds);
            ds.remove(ds.size() - 1);
        }
    }
    public static List < List < Integer >> combinationSum2(int[] candidates, int target) {
        List < List < Integer >> ans = new ArrayList < > ();
        Arrays.sort(candidates);
        findCombinations(0, candidates, target, ans, new ArrayList < > ());
        return ans;
    }
}
```
