/*
Similar Problems
4Sum
Two Sum IV - Input is a BST
Two Sum Less Than K */
/* Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
*/

    
    // Approach 1: Brute Force, bug : for( int j = i+1;  j <= nums.size(); j++){// j must be <= here!! EXCEED time limit even after fix bug

class Solution {   
public:
    int subarraySum(vector<int>& nums, int k) {
    int count = 0;
       for( int i = 0;  i < nums.size(); i++){         
         for( int j = i+1;  j <= nums.size(); j++){// j must be <= here!!
           int sum =0; 
              for (int m = i; m < j; m++)
                    sum += nums[m];
                if (sum == k)
                    count++;
            
            }    
        }      
         return count;   
    }
 };
    
/*
Time complexity : O(n^3)O(n 
3
 ). Considering every possible subarray takes O(n^2)O(n 
2
 ) time. For each of the subarray we calculate the sum taking O(n)O(n) time in the worst case, taking a total of O(n^3)O(n 
3
 ) time.

Space complexity : O(1)O(1). Constant space is used.

*/
