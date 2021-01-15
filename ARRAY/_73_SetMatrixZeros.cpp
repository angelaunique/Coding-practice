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
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.size() == 0) return;
    int m = matrix.size();
    int n = matrix[0].size();
    bool row = false;
    bool col = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
          if (i == 0) row = true;
          if (j == 0) col = true;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < n; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int j = 1; j < n; j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < m; i++) {
          matrix[i][j] = 0;
        }
      }
    }

    if (row) {
      for (int j = 1; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
    if (col) {
      for (int i = 1; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};