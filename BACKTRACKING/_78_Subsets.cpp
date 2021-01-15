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
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> list;
    if (nums.empty() || nums.size() == 0) return res;
    helper(res, list, nums, 0);
    return res;
  }
  void helper(vector<vector<int>>& res, vector<int>& list, vector<int>& nums,
              int index) {
    res.push_back(list);
    for (int i = index; i < nums.size(); i++) {
      list.push_back(nums[i]);
       helper(res, list, nums, i + 1);
      list.erase(list.end() - 1);
    }
  }
};
