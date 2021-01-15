/*
45. Jump Game II
Hard

2909

146

Add to List

Share
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

    /* JUMP GAME 1
class Solution {
  public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();

    // max position one could reach 
    // starting from index <= i
    int maxPos = nums[0];

    for (int i = 1; i < n; ++i) {
      // if one could't reach this point
      if (maxPos < i) {
        return false;
      }
      maxPos = max(maxPos, nums[i] + i);
    }
    return true;
  }
};
*//* DFS
class Solution {
  public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    // max position one could reach 
    // starting from index <= i 
    int maxPos = nums[0];
    // max number of steps one could do
    // inside this jump
    int maxSteps = nums[0];
    
    int jumps = 1;
    for (int i = 1; i < n; ++i) {
      // if to reach this point 
      // one needs one more jump
      if (maxSteps < i) {
        ++jumps;
        maxSteps = maxPos;
      }
      maxPos = max(maxPos, nums[i] + i);
    }
    return jumps;
  }
};*/

class Solution {
  public:
   int jump(vector<int>& nums) {
    
    int res = 0;
    int curMaxarea = 0;
    int maxNext = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
        maxNext = max(maxNext, nums[i] + i);
      // if one could't reach this point
      if (i == curMaxarea) {
          res++;
         curMaxarea = maxNext;
      }
    }
      return res;
  }
};