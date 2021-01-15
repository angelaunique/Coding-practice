
/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101" */

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        
        while(i >= 0 || j >= 0 )
        {
            int sum = carry;
            if( i >=0 ) sum+= a[i] -'0';
            if( j >=0 ) sum+= b[j] -'0';
            s += to_string(sum % 2);
            carry = sum/2;

            i--;
            j--;    
        }
        if(carry != 0 ) s+= to_string(carry);// last carry
        // string has reverse function
        reverse(s.begin(), s.end());// directly reverse begin ,end 新语法
        return s;
    }
};
  