/*
46. Permutations
Medium

4495

111

Add to List

Share
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
//看backtracking 图
/*
Approach 1: Backtracking
Backtracking is an algorithm for finding all solutions by exploring all potential candidates. If the solution candidate turns to be not a solution (or at least not the last one), backtracking algorithm discards it by making some changes on the previous step, i.e. backtracks and then try again.

Here is a backtrack function which takes the index of the first integer to consider as an argument backtrack(first).

If the first integer to consider has index n that means that the current permutation is done.
Iterate over the integers from index first to index n - 1.
Place i-th integer first in the permutation, i.e. swap(nums[first], nums[i]).
Proceed to create all permutations which starts from i-th integer : backtrack(first + 1).
Now backtrack, i.e. swap(nums[first], nums[i]) back.
*/
//https://www.youtube.com/watch?v=KukNnoN-SoY 很好但视频
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> res;
         permutation(nums,res,0);// start at index i = 0
         return res;    
    }
  
    void permutation(vector<int>& nums, vector<vector<int>>& res,int begin) {//res 必须得传进去&，要不得到空集
        
         if(begin == nums.size()) {
             // one permutation instance
             res.push_back(nums);//don't need a path,can directly push num into result
             return;
         }
           
         for(int i=begin;i< nums.size();i++) {//已经走过但数想象成把它从list中取掉
             swap(nums[begin], nums[i]);//第一侧深度搜多begin 和i 都是相同，所以不需要换，同步0，0；1，1；2，2；
             //path.push_back(elem); //every step put inside
             permutation(nums,res, begin+1);
             // reset
		    swap(nums[begin], nums[i]);
         }
    }  
};
