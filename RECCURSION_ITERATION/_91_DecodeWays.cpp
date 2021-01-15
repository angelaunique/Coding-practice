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
  int numDecodings(string s) {
    if (s.length() == 0 || s[0] == '0') {
      return 0;
    }
    int c1 = 1;
    int c2 = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == '0') {
        c1 = 0;
      }
      if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
        c1 = c1 + c2;
        c2 = c1 - c2;
      } else {
        c2 = c1;
      }
    }
    return c1;
  }
};