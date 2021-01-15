/*240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]*/
// Approach 4: Search Space Reduction
/*
Because the rows and columns of the matrix are sorted (from left-to-right and top-to-bottom, respectively), 
we can prune \mathcal{O}(m)O(m) or \mathcal{O}(n)O(n) elements when looking at any particular value.*/
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    const int m = matrix.size();
    const int n = matrix[0].size();
      // r,c 用任何一个方向的信息都行，但必须用=号的那个需要size-1，且--,小值++
    int r = 0;
    int c = matrix[0].size() - 1;

    while (r < m && c >= 0) {//can't use two for loops since it won't move flexibly , 
      if (matrix[r][c] == target) return true;
      else if (target < matrix[r][c] ) c--;// use conner case 15,19 to find this rule go up or go left
      else r++;// go right or go down, since we scan from le，
    }
    return false;
  }
};

  
//method2 binary search
class Solution {
    private boolean binarySearch(int[][] matrix, int target, int start, boolean vertical) {
        int lo = start;
        int hi = vertical ? matrix[0].length-1 : matrix.length-1;

        while (hi >= lo) {
            int mid = (lo + hi)/2;
            if (vertical) { // searching a row,boolean verticalFound (naming is not intuiitive,should me horizontal)= binarySearch(matrix, target, i, true);
                if (matrix[start][mid] < target) {//matrix[start][mid] --start is the 1st index, for row
                    lo = mid + 1;
                } else if (matrix[start][mid] > target) {
                    hi = mid - 1;
                } else {
                    return true;
                }
            } else { // searching a col  boolean horizontalFound (naming is not intuiitive,should me vertical)= binarySearch(matrix, target, i, false);
                if (matrix[mid][start] < target) {//matrix[mid][start] --start is the 2st index, for col
                    lo = mid + 1;
                } else if (matrix[mid][start] > target) {
                    hi = mid - 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }

      public boolean searchMatrix(int[][] matrix, int target) {
        // an empty matrix obviously does not contain `target`
        if (matrix == null || matrix.length == 0) {
            return false;
        }

        // iterate over matrix diagonals！！重要，减少需要search的数量
        int shorterDim = Math.min(matrix.length, matrix[0].length);
        for (int i = 0; i < shorterDim; i++) {// choose the shorter one
            boolean verticalFound = binarySearch(matrix, target, i, true);// search a row,col by col, ith col
            boolean horizontalFound = binarySearch(matrix, target, i, false);// search a col row by row, ith row
            if (verticalFound || horizontalFound) {// it searches both vertical and horizontal bc we are not sure which 
                return true;//one is smaller,row or col? thus to be safe and make sure we covers all the numbers we serched 
            }// both row and cols at the same time
        }
        
        return false; 
    }
}