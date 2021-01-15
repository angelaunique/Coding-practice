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
  int rob(vector<int>& nums) {
    int prevNo = 0;
    int prevYes = 0;
    for (int num : nums) {
      int temp = prevNo;
      prevNo = max(prevNo, prevYes);
      prevYes = num + temp;
    }
    return max(prevNo, prevYes);
  }
};