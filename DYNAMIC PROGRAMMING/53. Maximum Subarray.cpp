/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647

*

//Similar Problem
//Degree of an Array
//Longest Turbulent Subarray
//Approach 1: Divide and Conquer
/*
Intuition

The problem is a classical example of divide and conquer approach, and can be solved with the algorithm similar with the merge sort.

Let's follow here a solution template for the divide and conquer problems :

Define the base case(s).

Split the problem into subproblems and solve them recursively.

Merge the solutions for the subproblems to obtain the solution for the original problem.

Algorithm

maxSubArray for array with n numbers:

If n == 1 : return this single element.

left_sum = maxSubArray for the left subarray, i.e. for the first n/2 numbers (middle element at index (left + right) / 2 always belongs to the left subarray).

right_sum = maxSubArray for the right subarray, i.e. for the last n/2 numbers.

cross_sum = maximum sum of the subarray containing elements from both left and right subarrays and hence crossing the middle element at index (left + right) / 2.

Merge the subproblems solutions, i.e. return max(left_sum, right_sum, cross_sum).


*/

class Solution {
public:
     It is not mandatory to specify the number of rows in the array. However, the number of columns should always be specified.
    int crossSum(vector<int>& nums, int left, int right, int p) {//Important, change pass in parameter to (vector<int>&, otherwise won't match! 
    if (left == right) return nums[left];

    int leftSubsum =  -2147483648;
    
    
    int currSum = 0;
    for(int i = p; i > left - 1; --i) {
      currSum += nums[i];
      leftSubsum = max(leftSubsum, currSum);
    }

    int rightSubsum =  -2147483648;
    currSum = 0;
    for(int i = p + 1; i < right + 1; ++i) {
      currSum += nums[i];
      rightSubsum = max(rightSubsum, currSum);
    }

    return leftSubsum + rightSubsum;
  }

int helper(vector<int>& nums, int left, int right) {
        
    if (left == right) return nums[left];

    int p = (left + right) / 2;

    int leftSum = helper(nums, left, p); //left sub tree, each sub tree has left, cross and right; seletct the max recursively return to leftSum
    int rightSum = helper(nums, p + 1, right);//right sub tree each sub tree has left, cross and right; seletct the max recursively return to leftSum
    int croSum = crossSum( nums, left, right, p);// cross part

    return max(max(leftSum, rightSum), croSum);// max function in c++ can only takes two parameters
  }
    
    int maxSubArray(vector<int>& nums) {  

      return helper( nums, 0, nums.size() - 1);   
    }
    
    
};

/* Approach 2: Greedy
simiar problem:
Super Washing Machines,
Gas Problem.
Pick the locally optimal move at each step, and that will lead to the globally optimal solution.

The algorithm is general and straightforward: iterate over the array and update at each step the standard set for such problems:

current element

current local maximum sum (at this given point)

global maximum sum seen so far.  
 */

class Solution {
public:

     int maxSubArray(vector<int>& nums) {  

      int n = nums.size();
      int currSum = nums[0];
      int maxSum = nums[0];

    for(int i = 1; i < n; ++i) {
      currSum = max(nums[i], currSum + nums[i]);// compare front one with font+ previous sum ,current local maximum sum (at this given point)
      maxSum = max(maxSum, currSum);
    }
    return maxSum;//global maximum sum seen so far.
  }  
};    
 
/*
Approach 3: Dynamic Programming (Kadane's algorithm)

here are two standard DP approaches suitable for arrays:

Constant space one. Move along the array and modify the array itself.

Linear space one. First move in the direction left->right, then in the direction right->left. Combine the results. Here is an example.
Let's use here the first approach since one could modify the array to track the current local maximum sum at this given point.

Next step is to update the global maximum sum, knowing the local one.
*/
    
class Solution {
public:
     int maxSubArray(vector<int>& nums) {  
       int n = nums.size(), maxSum = nums[0];
        for(int i = 1; i < n; ++i) {// start from the second element, 
          if (nums[i - 1] > 0) nums[i] += nums[i - 1];// only pick the positive one to add
          maxSum = max(nums[i], maxSum);
        }
    return maxSum;
  }
};    




























    
    

    