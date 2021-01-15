
/*
Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list,
 and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // move along the input array starting from the end
        for (int idx = n - 1; idx >= 0; --idx) {
          // set all the nines at the end of array to zeros
          if (digits[idx] == 9) {
            digits[idx] = 0;
          }
          // here we have the rightmost not-nine
          else {
            // increase this rightmost not-nine by 1 
            digits[idx]++;//只需要加一个就可以return，因为是plus1
            // and the job is done
            return digits;
          }
        }
        // we're here because all the digits are nines! IMPORTANT!!!
        digits.insert(digits.begin(), 0);
        digits[0] = 1;
        return digits;
  }
    
};