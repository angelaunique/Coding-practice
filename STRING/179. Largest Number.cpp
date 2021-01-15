
/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"*/

/* for each pairwise comparison during the sort, we compare the numbers achieved by concatenating the pair in both orders.  TRANSITIVITY
 There is a minor edge case that comes up when the array consists of only zeroes, so if the most significant number is 00, we can simply return 00.
 
 Assume that (without loss of generality), for some pair of integers aa and bb, our comparator dictates that aa should precede bb in sorted order. This means that a\frown b > b\frown aa⌢b>b⌢a (where \frown⌢ represents concatenation). For the sort to produce an incorrect ordering, there must be some cc for which bb precedes cc and cc precedes aa. This is a contradiction because a\frown b > b\frown aa⌢b>b⌢a and b\frown c > c\frown bb⌢c>c⌢b implies a\frown c > c\frown aa⌢c>c⌢a. In other words, our custom comparator preserves transitivity, so the sort is correc
comparator preserves transitivity, so the sort is correct.

*/

class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            string ret;
            sort(nums.begin(),nums.end(),[](const int &m,const int&n){//[](const int &m,const int&n
                    return to_string(m)+to_string(n)>to_string(n)+to_string(m);});//to_string(m)
            
            
            for(int i=0;i<nums.size();++i){
                ret+=to_string(nums[i]);
            }
            if(ret[0]=='0') //for the case nums are all zeros
                return "0";
            return ret;
        }  
    };