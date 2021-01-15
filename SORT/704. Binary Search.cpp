/*704. Binary Search
Easy

807

48

Add to List

Share
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int m = (r - l) / 2 + l;
      if (nums[m] == target) 
        return m;
      else if (nums[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return -1;
  }
};