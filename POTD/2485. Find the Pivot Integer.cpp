#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)    return 1;
      int left =1, right =n;
      int sumLeft = left , sumRight = 0;
      while(left<=right){
        if( left == right ) return left;
        if( sumLeft < sumRight ){
            sumLeft += left;
            left++;
        }
        else if( sumRight<sumLeft){
            sumRight += right;
            right--;
        }else   return left;
      }
      return -1;
    }
};
};
int main(){

    Solution obj;
    obj.customSortString(order,s);
}