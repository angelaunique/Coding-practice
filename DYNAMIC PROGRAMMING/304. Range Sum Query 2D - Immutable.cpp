/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12*/


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {// 计算任何一个格子位置和的算法
        sums_.clear();
        if (matrix.empty()) return;
         int m = matrix.size();        
        int n = matrix[0].size();
        
        //// sums_[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
        sums_=vector<vector<int>> (m+1,vector<int>(n+1,0));// padding i,j index start from 1, so create sums dim m+1,n+1
   
        for(int i =1; i <=m;++i)
             for (int j = 1; j <= n; ++j)
                 sums_[i][j] = matrix[i - 1][j - 1]// only this one padding minus
                             + sums_[i - 1][j]+ sums_[i][j - 1] - sums_[i - 1][j - 1];
    }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {//任何格子的sums_已经算出，加起来即可
        /*
         return sums_[row2 + 1][col2 + 1]
             - sums_[row2 + 1][(col1-1)+1]
             - sums_[(row1-1)+1][col2 + 1]
             + sums_[(row1-1)+1][(col1-1)+1];//all the +1 are padding,( )is the original value*/
        return sums_[row2 +1 ][col2 +1 ]- sums_[row2 + 1][col1] -sums_[row1][col2 + 1] + sums_[row1][col1];  // padding +
    }
private:   
    vector<vector<int>> sums_;
};