/*673. Number of Longest Increasing Subsequence
Medium

1599

91

Add to List

Share
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
*/
///https://www.youtube.com/watch?time_continue=885&v=SFCiuIJu17Y&feature=emb_logo
// 两个 recursion被main call，而且 count 套用 len 求之，然后count 也被men 调用
// method1, recursion with memory 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        c_ = vector<int>(n, 0);
        l_ = vector<int>(n, 0);
        
        // Find the length LIS.
        //找到不同长度子序列(n) LIS 的最大值
        int max_len = 0;
        for (int i = 0; i < n; ++i)
            max_len = max(max_len, len(nums, i));
        
        // Checking all endings.
        //因为有很多 LIS 相同的不同长度子序列(n) ，要累加起来所有=max_len的lcs 数量/
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (len(nums, i) == max_len) //所有lcs=len(nums, i) = max_len的 子序列
                ans += count(nums, i);
        
        return ans;
    }//看视频细品
private:
    vector<int> c_; // c[i]: number of LIS ends with nums[i] / NLIS'---IMPORTANT!
    vector<int> l_; // l[i]: lengeh of LIS ends with nums[i] / LIS'----IMPORTANT!
    /*找 lcs数量的过程也是一个递归，方法：传入子序列，遍历子序列，如果子序列的lcs 值和我（n子系列）的值相同而且我nums[n] > nums[i] 说明我(n)最大的count 应该是k=count(nums, i) +1 因为我在你的lcs后面追加了一个 ， 那么现在的总计长度为k的子序列数量就是2了，以此类推。 求完序列为n的lcs数量后要返回到main，因为有很多 lcs 相同的不同长度子序列(n) ，要累加起来所有=max_len的lcs 数量*/
    // Number of LIS ends with nums[n]
    int count(const vector<int>& nums, int n) {
        if (n == 0) return 1;
        if (c_[n] > 0) return c_[n];
        
        int total_count = 0;
        int l = len(nums, n);
        for (int i = 0; i < n; ++i)
            if (nums[n] > nums[i] && len(nums, i) == l-1)// lis(i)== lis(n-1)，你和我之前的最大值长度相等，，现在我比你大一个了
                total_count += count(nums, i);
        //之前的total_count 已经计算过比如 （1，2，4）的lis =3, total_count =1;
        /*
         for (int i = 0; i < n; ++i)
            if (nums[n] > nums[i] && len(nums, i) == l-1)
         这两行计算的是 1,2,4,2.5,3 z这种情况下，得出的  total_count= count(nums, i)=2: (1,2,3)(1,2.5,3)
         //所以现在total_count=2+1=3
        
        */
        if (total_count == 0)
            total_count = 1;
        
        return c_[n] = total_count;
    }
    //找longest Increasing subsequence 的过程是一个递归
    // Length of LIS ends with nums[n]
    int len(const vector<int>& nums, int n) {
        if (n == 0) return 1;
        if (l_[n] > 0) return l_[n];
        
        int max_len = 1;
        
        // Check every subarray
        for (int i = 0; i < n; ++i)
            if (nums[n] > nums[i])
                max_len = max(max_len, len(nums, i) + 1);
        
        return l_[n] = max_len;
    }
};

/* method2 dp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> c(n, 1);
        vector<int> l(n, 1);
        
        for (int i = 1; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if (nums[i] > nums[j]) {
                    if (l[j] + 1 > l[i]) {
                        l[i] = l[j] + 1;
                        c[i] = c[j];
                    } else if (l[j] + 1 == l[i]) {
                        c[i] += c[j];
                    }
                }
        
        int max_len = *max_element(l.begin(), l.end());
        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (l[i] == max_len)
                ans += c[i];
        
        return ans;
    }
};*/