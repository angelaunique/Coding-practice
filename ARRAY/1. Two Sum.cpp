
/*
Similar Problems
4Sum
Subarray Sum Equals K
Two Sum IV - Input is a BST
Two Sum Less Than K */

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

//no dupilicate


// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   
      vector<int> v;
       for( int i = 0;  i < nums.size(); i++){         
         for( int j = i+1;  j < nums.size(); j++){// key! j = i+1 not 1!!!
           if(nums[j] == target - nums[i] ) {
               v.push_back(i);
               v.push_back(j);
               return v; 
                }   
            }    
        }      
        return v; 
    }          
};

/*
Time complexity : O(n^2)O(n 
2
 ). For each element, we try to find its complement by looping through the rest of array which takes O(n)O(n) time. Therefore, the time complexity is O(n^2)O(n 
2
 ).

Space complexity : O(1)*/

/*Approach 2: Two-pass Hash Table  提取出一个for loop 用于建立hashtable！
To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. If the complement exists, we need to look up its index. 
We reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed.
We reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed. A hash table is built exactly for this purpose, it supports fast look up in near constant time. I say "near" because if a collision occurred, a look up could degenerate to O(n)O(n) time. But look up in hash table should be amortized O(1)O(1) time as long as the hash function was chosen carefully.
A simple implementation uses two iterations. In the first iteration, we add each element's value and its index to the table. Then, in the second iteration we check if each element's complement (target - nums[i]target−nums[i]) exists in the table. Beware that the complement must not be nums[i]nums[i] itself!
*/
// similar to method 3, but has bug,  reason: must have m[target-nums[i]] != i in if condition, otherwise return (0,0)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m.insert({ nums[i], i });
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)// 找到 complement 值！seaching is constant time here! another one can't be i itself, bc we want two dffierent number sum up to target
            // must have m[target-nums[i]] != i in if condition, otherwise return (0,0), method three doesn't need this bc automatically check to val ==i when add into map after return line
                return {m[target-nums[i]], i}; //return, 
           // m[nums[i]] = i;//如果没找到，加入map 第一个for loop 可用此行替代，为approach 3
        }
         return {};
    }
};

//running time 24 ms! >> 1028 ms
/*
Approach 3: One-pass Hash Table
It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())// 找到 complement 值！seaching is constant time here!
            return {m[target-nums[i]], i}; //return, 
            m[nums[i]] = i;//如果没找到，加入map
        }
         return {};
    }
};

/*
Time complexity : O(n)O(n). We traverse the list containing nn elements only once. Each look up in the table costs only O(1) time.

Space complexity : O(n) The extra space required depends on the number of items stored in the hash table, which stores at most n elements.*/
    

