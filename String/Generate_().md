# Intuition

## Approach

Here's the algorithm expressed in plain English for generating well-formed parentheses:

Function `generateParenthesis(n)`:

- Takes an integer `n` as input, representing the desired number of parentheses pairs.
- Initializes three variables:
  - `l` (integer): Keeps track of the current number of opening parentheses (`(`).
  - `r` (integer): Keeps track of the current number of closing parentheses (`)`).
  - `ans` (vector of strings): Stores all the valid combinations of parentheses to be returned.
- Calls the recursive helper function `count` with an empty string `temp`, `n` (initial number of parentheses), `l` initialized to 0 (no opening parentheses yet), and `r` initialized to 0 (no closing parentheses yet).
- Returns the `ans` vector containing all the generated valid combinations.

Recursive Helper Function `count(ans, temp, n, l, r)`:

- Takes five arguments:
  - `ans` (vector of strings): Reference to the output vector to store valid combinations.
  - `temp` (string): Represents the current partially constructed combination of parentheses.
  - `n` (integer): Total number of parentheses pairs to generate.
  - `l` (integer): Current number of opening parentheses in `temp`.
  - `r` (integer): Current number of closing parentheses in `temp`.
- Base Case:
  - If `l` and `r` are both equal to `n` (all parentheses placed):
    - The `temp` string represents a valid combination.
    - Add `temp` to the `ans` vector.
    - Return from the current function call (backtracking).
- Recursive Exploration:
  - If `l` is less than `n` (can add more opening parentheses):
    - Append an opening parenthesis `'('` to `temp`.
    - Make a recursive call to `count` with the updated `temp`, incremented `l` (`l + 1`), and unchanged `r` to explore further combinations.
    - After the recursive call (backtracking), remove the appended opening parenthesis from `temp`.
  - If `r` is less than `l` (maintain validity with more opening parentheses):
    - Append a closing parenthesis `')'` to `temp`.
    - Make a recursive call to `count` with the updated `temp`, unchanged `l`, and incremented `r` (`r + 1`) to explore further combinations.
    - After the recursive call (backtracking), remove the appended closing parenthesis from `temp`.

This algorithm recursively explores all possible combinations by strategically adding opening and closing parentheses, ensuring validity through backtracking when necessary.

## Complexity

- Time complexity: O(4^n / sqrt(n))
- Space complexity: O(n)

```
class Solution {
public:

    void count(vector<string> &ans , string temp , int n, int l, int r){
        if(l==n && r==n) {
            ans.push_back(temp);
            return ;
        }
        if(l<n){
            temp.push_back('(');
            count(ans , temp ,n,l+1,r);
            temp.pop_back();
        }
        if(r<l){
            temp.push_back(')');
            count(ans , temp ,n,l,r+1);
            temp.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        int l=0,r=0;
        vector<string> ans;
        string temp;
        count(ans , temp ,n,l,r);
        return ans;

    }
};
```