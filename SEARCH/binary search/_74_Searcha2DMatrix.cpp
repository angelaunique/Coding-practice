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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.size() == 0) return false;
    int row = matrix.size();
    int col = matrix[0].size();

    int begin = 0;
    int end = row * col - 1;
    while (begin <= end) {
      int mid = (end - begin) / 2 + begin;
      int value = matrix[mid / col][mid % col];
      if (value == target) {
        return true;
      } else if (value < target) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};
