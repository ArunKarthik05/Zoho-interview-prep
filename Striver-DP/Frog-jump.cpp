#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int n, vector<int> &heights,vector<int> &dp){
        cout<<"\nCalling index"<<i;
        if( i ==0 )   return 0;
        if( dp[i]!=-1)  return dp[i];
        int oneJump = INT_MAX;
        cout<<"\nOnejump:"<<oneJump;
        oneJump = f(i-1, n, heights,dp) + abs(heights[i]-heights[i-1]);
        int twoJump = INT_MAX;
        if( i>1)
             twoJump = f(i-2, n, heights, dp) + abs( heights[i]-heights[i-2]);
        cout<<"\nReturning "<<i<<":"<<min(oneJump,twoJump);
        return dp[i] = min(oneJump,twoJump);

    }
    int frogJump(int n, vector<int> &heights){
        vector<int> dp(n,-1);
        return f(n-1,n,heights,dp);
    }
};
int main(){
    vector<int> heights = {10,10,60,10,20};
    Solution obj;
    int ans = obj.frogJump(heights.size(),heights);
        cout<<"\nAns:"<<ans;
}

/*
QUESTION:
There is a frog on the '1st' step of an 'N' stairs long staircase. 
The frog wants to reach the 'Nth' stair. 
'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, 
the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
INPUT:
2
4
10 20 30 10
3
10 50 10
Sample Output 1:
20
0
*/

/*
SOLUTION: Think of a recursive way first

Memoize each step
a.Create a dp array and initialize to -1
b.Return dp[i] if it has been calculated(Overlapping sub-problems)

Then Tabulate
Then optimize the space if possible
*/