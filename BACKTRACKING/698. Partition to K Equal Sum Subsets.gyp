'''698. Partition to K Equal Sum Subsets
Medium

2258

134

Add to List

Share
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.'''

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        nums.sort(reverse=True)
        if m or max(nums) > target: # important step, otherwise won't pass
            return False
        def helper(nums, target, cur, rest):
            if rest == 0 and not nums: # 如果已经分完而且nums 为空，说明能够整分
                return True
            if not nums: return False #如果nums一开始为空，false
            for i in range(len(nums)):
                if cur + nums[i] > target: continue
                temp = False
                if cur + nums[i] == target:#找到一个组合
                    temp = helper(nums[:i] +nums[i+1:],target,0,rest -1)
                else: #if < target，cur + nums[i]
                    temp = helper(nums[:i] +nums[i+1:],target,cur + nums[i],rest)
                if temp: #if temp is True,
                    return temp
            return False # return false otherwise
        target, m = divmod(sum(nums), k)
        if m:
            return False 
        return helper(nums, target, 0, k)
    
  # method 2 
    
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
    total = sum(nums)
    if total % k != 0: # if not possible to divide equally
        return False
    targets = [total // k] * k
    taken = [False] * len(nums) # mark if the element is used for adding up a sum
    
    def backtrack(i, k_th):
        if targets[k_th] < 0: # if the target has become negative, definitely False, this is to terminate early
            return False
        if targets[k_th] == 0: # if the sum is successfully formed
            if k_th == k - 1: # finished completing all the target sums
                return True
            return backtrack(0, k_th + 1) # go to the next target sum
        
        # looping all the subsequent elems to see if there is a successful groups of ints forming sums
        for j in range(i, len(nums)): 
            if taken[j]: # if used the elem in nums, go to the next one
                continue
            taken[j] = True # mark as used
            targets[k_th] -= nums[j] # update the target sum
            if backtrack(j + 1, k_th): # if successfully found the complete set of sum by using the current elem in k_th target
                return True
            taken[j] = False # unmark as not used
            targets[k_th] += nums[j] # revert back to the original sum for the next loop to use
            
        return False
    
    return backtrack(0, 0)