/*
1328. Break a Palindrome

Add to List

Share
Given a palindromic string palindrome, replace exactly one character by any lowercase English letter 
so that the string becomes the lexicographically smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.
Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Example 2:

Input: palindrome = "a"
Output: ""*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';//if all letters are 'a'
        return n < 2 ? "" : palindrome;
        }
};
