/**
 75. Sort Colors
Medium

4057

238

Add to List

Share
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() == 0) return;
        int left = 0;
        int right = nums.size() - 1;
        int index = 0;
        while (index <= right) {
            if (nums[index] == 0) {
                swap(nums, index++,left++);
            } else if (nums[index] == 1){
                index++;
            } else {
                swap(nums, index, right--);
            }
        }
        
    }   
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
//better code
void sortColors(vector<int>& nums) {
    int zero =0, l = 0, r = nums.size()-1;
    while (l <= r) {
        if (nums[l] == 0) 
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2) 
            swap(nums[l], nums[r--]);
        else
            l++;
    }
}