/*69. Sqrt(x)
Easy

1510

2020

Add to List

Share
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.*/
Solution 1: Brute force
Time complexity: sqrt(x)

// Running time: 40 ms
class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) return x;
    for (long long s = 1; s <= x; ++s)
      if (s * s > x) return s - 1;
    return -1;
  }
};
Solution 2: Binary search
Time complexity: O(logn)

// Author: Huahua
// Running time: 12 ms
class Solution {
public:
  int mySqrt(int x) {      
    long l = 1;
    long r = static_cast<long>(x) + 1;
    while (l < r) {
      long m = l + (r - l) / 2;
      if (m * m > x) { 
        r = m;
      } else {
        l = m + 1;
      }
    }
    // l: smallest number such that l * l > x
    return l - 1;
  }
};