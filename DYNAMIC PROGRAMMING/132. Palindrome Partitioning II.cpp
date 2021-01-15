
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1

//方法一： 常规dp 思想，切割

class Solution {
public:
  int minCut(string s) {
    const int n = s.length();
    // valid[i][j] = 1 if s[i~j] is palindrome, otherwise 0
    vector<vector<int>> valid(n, vector<int>(n, 1));
    
    // dp[i] = min cuts of s[0~i] 
    vector<int> dp(n, n);// 不合法的情况
    // build truth table
    for (int l = 2; l <= n; ++l) 
      for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
    // next to loop through to check ispanlindrom, if true, continue
    for (int i = 0; i < n; ++i) {      
      if (valid[0][i]) { // 枚举右端点
        dp[i] = 0;//if valid, cut = 0
        continue;
      }// esle, if false, 枚举所有的分割点，从0 到i-1
      for (int j = 0; j < i; ++j) // 枚举子问题
        if (valid[j + 1][i])//如果右边部分合法
          dp[i] = min(dp[i], dp[j] + 1);  //dp[i] 就在dp[i]（i is looped through the upper loop) 和 dp[j] + 1 中取一个最小值
    }  // 如果不合法已经被初始化为n
    return dp[n - 1];//最后答案存储在此
  }
};

