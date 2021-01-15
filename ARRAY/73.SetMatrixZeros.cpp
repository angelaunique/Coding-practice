/**
3. Set Matrix Zeroes
Medium

2560

335

Add to List

Share
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
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