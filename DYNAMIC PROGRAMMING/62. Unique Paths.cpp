
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
*/

/*Approach 1: time limit ecxeed
This solution is not fast enough to pass all the testcases, though it could be used as a starting point for the DP solution.
class Solution {
public:
    int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) {
      return 1;
    }
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
  }
        
};
*/

/*
Approach 1: Dynamic Programming
One could rewrite recursive approach into dynamic programming one.

Algorithm

Initiate 2D array d[m][n] = number of paths. To start, put number of paths equal to 1 for the first row and the first column. For the simplicity, one could initiate the whole 2D array by ones.

Iterate over all "inner" cells: d[col][row] = d[col - 1][row] + d[col][row - 1].

Return d[m - 1][n - 1].
*/
class Solution {
    public:
    int uniquePaths(int m, int n) {
        
        if(n==0 || m==0) return 0;

        vector<vector<int>>   Dp(n,vector<int>(m,1)); // initialize the whole matrix to 1

        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                Dp[i][j]=Dp[i-1][j]+Dp[i][j-1];

        return Dp[n-1][m-1]; // return the last bottom right cell
    }
};