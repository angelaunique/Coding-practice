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
  int minPathSum(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (i == 0 && j != 0) grid[i][j] += grid[i][j - 1];
        if (i != 0 && j == 0) grid[i][j] += grid[i - 1][j];
        if (i != 0 && j != 0) {
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
      }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};
