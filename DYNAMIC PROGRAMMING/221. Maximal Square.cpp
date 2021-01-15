/*
221. Maximal Square
Medium

3520

90

Add to List

Share
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4 */

//更general的方法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // sums[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)        
                sums[i][j] = matrix[i - 1][j - 1] - '0' 
                             + sums[i - 1][j]
                             + sums[i][j - 1]
                             - sums[i - 1][j - 1];
        
        int ans = 0;
        for (int i = 1; i <= m; ++i)//i=1  ， look at the website, starting point is x,y(i,j) move from 从左到右边，从右到左
        //然后x+k,y+k ，k是size，加不同的size，一直往右往下延展就能遍历所有正方形，因为是从最左上角的小正方开始走；
        //任何一个正方都可以用这种方式被cover到
            for (int j = 1; j <= n; ++j)//j=1 //不同边长的正方形，第二个 5- 1 + 1=5，5-2+1=4，size4 
                for (int k = min(m - i + 1, n - j + 1); k > 0; --k) {//每个square 
                    int sum = sums[i + k - 1][j + k - 1]
                            - sums[i + k - 1][j - 1]
                            - sums[i - 1][j + k - 1]
                            + sums[i - 1][j - 1];
                    // full of 1
                    if (sum == k*k) {//如果此正方形的sum和k*k相等，那么就选择为此轮的答案
                        ans = max(ans, sum);
                        break;
                    }
                }
 
        return ans;
    }
};

/*
dp[x][y] = dp[y][x-1] +dp[y-1][x] -dp[y-1][x-1] + matrix[y][x] // matrix 中的index x,y start from 0, but dp中的index, x,y start from 1
dp[1][1] = dp[1][0] +dp[0][1]-dp[0][0]+matrix[0][0]

*/

// 是binary ，可以利用binary特性来进行dynamic programming
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> sizes(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                sizes[i][j] = matrix[i][j] - '0';
                
                if (!sizes[i][j]) continue;   //如果是0，跳过，如果是1，继续下面的code                        
                
                if (i == 0 || j == 0) {//最左上角的squre，没有左，上，左上
                    // do nothing
                } else if (i == 0)//第一行，只有左边的，所以选择左边的元素+1，eg： 1+1 = 2，1，1，一个边长为1，另一个边长为2，所以面积为2
                    sizes[i][j] = sizes[i][j - 1] + 1;
                else if (j == 0)//第一列，只有上面的，所以选择上边的元素+1，eg： 1+1 = 2，1，1，一个边长为1，另一个边长为2，所以面积为2
                    sizes[i][j] = sizes[i - 1][j] + 1;
                else//其他的都有左，上，左上，选择三个corner的最小值
                    sizes[i][j] = min(min(sizes[i - 1][j - 1], 
                                          sizes[i - 1][j]),
                                          sizes[i][j - 1]) + 1;
                
                ans = max(ans, sizes[i][j]*sizes[i][j]);
            }
        return ans;
    }
};
//还可以继续优化，因为只和上一行和上一列有关
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int> (matrix[0].size()+1,0));
        int maxi=0;
        for(int i=1;i<=matrix.size();i++)
        {
            for(int j=1;j<=matrix[0].size();j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                    maxi=max(maxi,dp[i][j]);
                    
                   //dp[i][j] = min(min(dp[i - 1][j - 1],  dp[i - 1][j]), dp[i][j - 1]) + 1;
                    //  ans = max(ans, dp[i][j]*dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};

