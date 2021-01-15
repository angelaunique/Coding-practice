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
  int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
      res = res * 26 + (s[i] - 'A' + 1);
    }
    return res;
  }
};
