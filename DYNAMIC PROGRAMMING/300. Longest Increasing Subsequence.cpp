/*

Increasing Triplet Subsequence
Russian Doll Envelopes
Maximum Length of Pair Chain
Number of Longest Increasing Subsequence
Minimum ASCII Delete Sum for Two Strings
300. Longest Increasing Subsequence
Medium

5436

121

Add to List

Share
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

*/


// method0 c++ dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        auto f = vector<int>(n, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    f[i] = max(f[i], f[j] + 1);
        return *max_element(f.begin(), f.end());// 返回f array中最大值
    }
};
// method 1 java dp
public class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < dp.length; i++) {
                        int maxval = 0;//内环找出j 行最大值
                        for (int j = 0; j < i; j++) {
                            if (nums[i] > nums[j]) {
                                maxval = Math.max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;//外环，包括s[i],总共maxval + 1 个
            maxans = Math.max(maxans, dp[i]);
        }
        return maxans;
    }
}

// method0 c++ dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        auto f = vector<int>(n, 1);// start with 1 since at least one element
        for (int i = 1; i < n; ++i)//i 值每次也是从头开始，比j大1个从1开始，animation上面大一行为input
            for (int j = 0; j < i; ++j)// j is in the front , i = 1, j = 0,j always start from 0, thus we will get an f[i] = f[j]+1          
        
                if (nums[i] > nums[j])// which represent the lenght, but since we want the max one,
                  // It is possible that T[i] already has larger value from some previous j'th iteration
					if(f[j] + 1 > f[i])
					{
                       // cout<<"f[j]:"<< f[j] << " ";
                        //f[j]:1 f[j]:1 f[j]:1 f[j]:2 f[j]:1 f[j]:2 f[j]:3 f[j]:1 f[j]:2 f[j]:3 
                        //f[i]:2 f[i]:2 f[i]:2 f[i]:3 f[i]:2 f[i]:3 f[i]:4 f[i]:2 f[i]:3 f[i]:4 
						f[i] = f[j] + 1;//f[j] 每次has to start from 0 因为f[j]不一定是最大大值，前面有可能有更长的sub sequence， f[j]记录的也是片段，只不过比i少一个length
                        cout<<"f[i]:"<< f[i] << " ";
					}
        return *max_element(f.begin(), f.end());// 返回f array中最大值
    }
};

//Solution 2: recursion with memoization

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;        
        f_ = vector<int>(n, 0);        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, LIS(nums, i));
        return ans;
    }
private:
    vector<int> f_;
    // length of LIS ends with nums[r]
    int LIS(const vector<int>& nums, int r) {
        if (r == 0) return 1;//boundary
        if (f_[r] > 0) return f_[r];//boudary
        int ans = 1; // key!!initialze to 1
        for(int i = 0; i < r; ++i)
            if (nums[r] > nums[i])
                ans = max(ans, LIS(nums, i) + 1);//recursion part
        f_[r] = ans;// filled recursion
        return f_[r];
    }
};
/*
Approach 4: Dynamic Programming with Binary Search
Algorithm

In this approach, we scan the array from left to right. We also make use of a dpdp array initialized with all 0's. This dpdp array is meant to store the increasing subsequence formed by including the currently encountered element. While traversing the numsnums array, we keep on filling the dpdp array with the elements encountered so far. For the element corresponding to the j^{th}j 
th
  index (nums[j]nums[j]), we determine its correct position in the dpdp array(say i^{th}i 
th
  index) by making use of Binary Search(which can be used since the dpdp array is storing increasing subsequence) and also insert it at the correct position. An important point to be noted is that for Binary Search, we consider only that portion of the dpdp array in which we have made the updates by inserting some elements at their correct positions(which remains always sorted). Thus, only the elements upto the i^{th}i 
th
  index in the dpdp array can determine the position of the current element in it. Since, the element enters its correct position(ii) in an ascending order in the dpdp array, the subsequence formed so far in it is surely an increasing subsequence. Whenever this position index ii becomes equal to the length of the LIS formed so far(lenlen), it means, we need to update the lenlen as len = len + 1len=len+1.

Note: dpdp array does not result in longest increasing subsequence, but length of dpdp array will give you length of LIS.

Consider the example:

input: [0, 8, 4, 12, 2]

dp: [0]

dp: [0, 8]

dp: [0, 4]

dp: [0, 4, 12]

dp: [0 , 2, 12] which is not the longest increasing subsequence, but length of dpdp array results in length of Longest Increasing Subsequence.*/

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }
}
/*
Note: Arrays.binarySearch() method returns index of the search key, if it is contained in the array, else it returns (-(insertion point) - 1). The insertion point is the point at which the key would be inserted into the array: the index of the first element greater than the key, or a.length if all elements in the array are less than the specified key.

Complexity Analysis

Time complexity : O(n\log n)O(nlogn). Binary search takes \log nlogn time and it is called nn times.

Space complexity : O(n)O(n). dpdp array of size nn is used.*/