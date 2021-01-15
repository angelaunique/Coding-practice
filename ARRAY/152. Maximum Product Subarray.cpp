/*

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


// brute force exceed time limits
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }
        return result;
    }
    
};

// brute force exceed time limits
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;

            result = max(max_so_far, result);
        }
        return result;  
    }
};
