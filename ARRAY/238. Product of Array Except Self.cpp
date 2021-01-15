/* 
Next challenges:
Maximum Product Subarray
Paint House II
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

//https://leetcode.com/problems/product-of-array-except-self/discuss/776664/C%2B%2B-oror-3-Approaches-oror-Easy-to-understand
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { // vector passed by reference
 
        vector<int> lhs(nums.size(), 1);
        vector<int> rhs(nums.size(), 1);
        // Left array
        for(int i = 1; i < nums.size();i++){
            lhs[i] = lhs[i-1] * nums[i-1];
        }
        // right array
        for(int i = nums.size()-1 ; i >= 1 ; i--){
            rhs[i-1] = rhs[i] * nums[i];
        }
        // result array
        for(int i = 0;i<nums.size() ;i++){
            nums[i] = lhs[i] * rhs[i];
        }
        return nums;
    }
};

        
// method 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int zeroCount = 0;
        int firstZeroIndex = -1;
        for(int i = 0; i<nums.size() ; i++){
            if( nums[i] == 0 ){
                zeroCount++;
                firstZeroIndex = i;
                if(zeroCount > 1){
                    return vector(nums.size(), 0);
                }
            }else{
                totalProduct *= nums[i];
            }
        }
        for(int i = 0; i< nums.size() ; i++){
            if(zeroCount == 1){
                if(i == firstZeroIndex){
                    nums[i] = totalProduct;
                }else{
                    nums[i] = 0;
                }
            }else{
                nums[i] = totalProduct/nums[i];
            }
        }
        return nums;
    }
};

// method 3
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lhs(nums.size(), 1);
        int rhs = 1;
        for(int i = 1; i<nums.size() ; i++){
            lhs[i] = lhs[i-1] * nums[i-1];
        }
        for(int i = lhs.size()-1; i >= 1 ; i--){
            rhs *= nums[i];
            lhs[i-1] *= rhs;
        }
        return lhs;
    }
};
