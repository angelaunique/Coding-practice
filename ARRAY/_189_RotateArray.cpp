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
  void rotate1(vector<int>& nums, int k) {
    int* temp = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++) {
      temp[(i + k) % nums.size()] = nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = temp[i];
    }
  }
};

/* method2*/
class Solution {
 public:
  void rotate2(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }
  void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
    }
  }
};