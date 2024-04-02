# 1.Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

### Example 1:
**Input:** s = "the sky is blue"<br>
**Output:** "blue is sky the"<br>

### Example 2:
**Input:** s = "  hello world  "<br>
**Output:** "world hello"<br>
**Explanation:** Your reversed string should not contain leading or trailing spaces.

### Example 3:
**Input:** s = "a good   example"<br>
**Output:** "example good a"<br>
**Explanation:** You need to reduce multiple spaces between two words to a single space in the reversed string.

```java
class Solution {
    public String reverseWords(String s) {
        char [] in = s.toCharArray();
        int n = s.length(); 
        reverse(in,0,n-1);
        reverseWords(in,n);
        int last = clearSpaces(in,n);
        return new String(in,0,last);
    }

    void reverse(char [] arr, int start, int end){
        while(start < end){
            char temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
    }

    void reverseWords(char [] arr, int n){
        int i = 0, j = 0; 
        while(i < n){
            while(i < n && arr[i] == ' ') i++;
            j = i+1;
            while(j < n && arr[j] != ' ') j++;
            reverse(arr,i,j-1);
            i = j;
        }
    }

    int clearSpaces(char [] arr, int n){
        int i = 0, j = 0;
        while(i < n){
            while(i < n && arr[i] == ' ') i++;
            while(i < n && arr[i] != ' ') arr[j++] = arr[i++];
            while(i < n && arr[i] == ' ') i++;
            if(i < n)
                arr[j++] = ' ';
        }
        return j;
    }
}
```

#
# 2.Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.


### Example 1:
**Input:** s = "babad"<br>
**Output:** "bab"<br>
**Explanation:** "aba" is also a valid answer.

### Example 2:
**Input:** s = "cbbd"<br>
**Output:** "bb"<br>

```java
class Solution {
    public String longestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }
        String maxStr = s.substring(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            String odd = expandFromCenter(s, i, i);
            String even = expandFromCenter(s, i, i + 1);

            if (odd.length() > maxStr.length()) {
                maxStr = odd;
            }
            if (even.length() > maxStr.length()) {
                maxStr = even;
            }
        }

        return maxStr;
    }
    public String expandFromCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }
}
```

#
# 3.Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

| Symbol   | Value |
| -------- | ------- |
| I        |      1 |
| V        |      5 |
| X        |      10 |
| L        |      50 |
| C        |      100 |
| D        |      500 |
| M        |      1000 |


For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.


### Example 1:
**Input:** s = "III"<br>
**Output:** 3<br>
**Explanation:** III = 3.<br>

### Example 2:
**Input:** s = "LVIII"<br>
**Output:** 58<br>
**Explanation:** L = 50, V= 5, III = 3.<br>

### Example 3:
**Input:** s = "MCMXCIV"<br>
**Output:** 1994<br>
**Explanation:** M = 1000, CM = 900, XC = 90 and IV = 4.<br>

```java
class Solution {
    static int value(char x, char y) {
        switch (x) {
            case 'I':
                if (y == 'V' || y == 'X')
                    return -1;
                return 1;
            case 'V':
                return 5;
            case 'X':
                if (y == 'L' || y == 'C')
                    return -10;
                return 10;
            case 'L':
                return 50;
            case 'C':
                if (y == 'D' || y == 'M')
                    return -100;
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    public int romanToInt(String s) {
        int n = s.length();
        int val = value(s.charAt(n - 1), ' ');
        for (int i = n - 2; i >= 0; i--) {
            val += value(s.charAt(i), s.charAt(i + 1));
        }
        return val;
    }
}
```

# 
# 4.String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
1. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
1. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
1. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
1. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
1. Return the integer as the final result.
#### Note:

- Only the space character ' ' is considered a whitespace character.
- Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 


### Example 1:
**Input:** s = "42"<br>
**Output:** 42<br>
**Explanation:** <br>
The underlined characters are what is read in, the caret is the current reader position.<br>
1. Step 1: "42" (no characters read because there is no leading whitespace)
         ^
1. Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
1. Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.

### Example 2:
**Input:** s = "   -42"<br>
**Output:** -42<br>
**Explanation:**<br>
1. Step 1: "   -42" (leading whitespace is read and ignored)
            ^
1. Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
1. Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

### Example 3:
**Input:** s = "4193 with words"<br>
**Output:** 4193<br>
**Explanation:**<br>
1. Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
1. Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
1. Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 


```java
class Solution {
    public int myAtoi(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int ans = 0, sign = 1, i = 0;
        int n = s.length();

        while(i < n && s.charAt(i) == ' ') i++;
        if(i >= n){
            return 0;
        }
        
        if(s.charAt(i) == '-'){
            sign = -1;
            i++;
        }
        else if(s.charAt(i) =='+'){
            i++;
        }

        while(i < n ){
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9'){
                int digit = s.charAt(i)-'0';
                if (ans > Integer.MAX_VALUE / 10 || 
                    (ans == Integer.MAX_VALUE / 10 && 
                        digit > Integer.MAX_VALUE % 10)) 
                    return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                ans = (ans * 10) + digit;
                i++;
            }
            else
                return ans*sign;
        }
        return ans*sign;
    }
}
```

#
# 5.Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

### Example 1:
**Input:** strs = ["flower","flow","flight"]<br>
**Output:** "fl"<br>

### Example 2:
**Input:** strs = ["dog","racecar","car"]<br>
**Output:** ""<br>
**Explanation:** There is no common prefix among the input strings.

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 1) return strs[0];
        int len = Integer.MAX_VALUE-1;
        for(String s: strs){
            if(s.length() < len){
                len = s.length();
            }
        }
        if(len == 0) return "";
        int i;
        for(i = 0; i < len; i++){
            char c = strs[0].charAt(i);
            for(int j = 1; j < strs.length; j++){
                if(strs[j].charAt(i) != c){
                    return strs[0].substring(0,i);
                }
            }
        }
        return strs[0].substring(0,i);
    }
}
```

#
# 6.Repeated String Match

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

**Notice:** string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".


### Example 1:
**Input:** a = "abcd", b = "cdabcdab"<br>
**Output:** 3<br>
**Explanation:** We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

### Example 2:
**Input:** a = "a", b = "aa"<br>
**Output:** 2<br>

```java
class Solution {
    public int repeatedStringMatch(String a, String b) {
        boolean[] bucket = new boolean[26];
        for (char c : a.toCharArray()) bucket[c - 'a'] = true;
        for (char c : b.toCharArray()) 
            if (!bucket[c - 'a']) return -1;
        
        String main = "";
        int count = 0;
        while(main.length() < b.length()){
            if(main.indexOf(b) != -1){
                return count;
            }
            count++;
            main += a;
        }
        if(main.indexOf(b) != -1){
            return count;
        }
        main += a;
        if(main.indexOf(b) != -1){
            return ++count;
        }
        return -1;
    }
}
```


