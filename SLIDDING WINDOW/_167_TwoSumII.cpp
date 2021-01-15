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
  vector<int> twoSum(vector<int>& numbers, int target) {
    if (numbers.empty() || numbers.size() < 2) {
      return {-1, -1};
    }

    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (target == sum) {
        return {left + 1, right + 1};
      } else if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
    return {-1, -1};
  }
};
