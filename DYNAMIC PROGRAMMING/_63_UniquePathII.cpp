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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int length = obstacleGrid[0].size();
    int res[length];
    res[0] = 1;
    for (int i = 1; i < sizeof(res) / sizeof(res[0]); i++) {
      res[i] = 0;
    }

    for (int i = 0; i < obstacleGrid.size(); i++) {
      for (int j = 0; j < obstacleGrid[0].size(); j++) {
        if (obstacleGrid[i][j] == 1) {
          res[j] = 0;
        } else if (j > 0) {
          res[j] += res[j - 1];
        }
      }
    }
    return res[length - 1];
  }
};