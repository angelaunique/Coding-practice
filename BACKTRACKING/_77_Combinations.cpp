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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> list;
    helper(res, list, n, k, 1);
    return res;
  }

  void helper(vector<vector<int>>& res, vector<int>& list, int n, int k,
              int start) {
    if (k == 0) {
      res.push_back(list);
      return;
    }
    for (int i = start; i <= n; i++) {
      list.push_back(i);
      helper(res, list, n, k - 1, i + 1);
      list.erase(list.end() - 1);
    }
  }
};
