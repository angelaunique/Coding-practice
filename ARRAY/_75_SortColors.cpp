/**
 * 本代码来自 CSON 官方视频课程，由 @CSON 提供
 * 题目来源：http://leetcode.com
 * - CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
 * - 讲师：Edward Shi
 * - 官方网站：https://cspiration.com
 * - 版权归CSON所有，禁止转载
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