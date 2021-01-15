/*907. Sum of Subarray Minimums

smiliar question
Find First and Last Position of Element in Sorted Array
Largest Rectangle in Histogram
Number of Equivalent Domino Pairs

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 */
 // my solution works but exceed time limit
 class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        vector<int> res;
        vector<int> subA;
        // find all subarrays
        // start with size full size, then decrement size, then find out sub continus array of subarray
        //vector<int>::iterator it = nums.begin();
        int size = 1;
        int n = A.size();
        while( size <= n){
         for( int j = 0;j < A.size();j++ ){// every size of subArr starts with 0
             //advance(it, i);
             if( j+size <= n){
             subA = {A.begin()+j, A.begin()+j+size};// {} not ()!!!
             int minA = *min_element(subA.begin(), subA.end()); 
             res.push_back(minA);    
             }
          }
            size++;
        }
        return  accumulate(res.begin(), res.end(),0);
        //accumulate(first_index, last_index, initial value of sum);
        
    }

};
//Best explaination
//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

class Solution {
public:
  int sumSubarrayMins(vector<int>& A) {
    stack<pair<int, int>> in_stk_p, in_stk_n;
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector<int> left(A.size()), right(A.size());
		
    //initialize
    for(int i = 0; i < A.size(); i++) left[i] =  i + 1;
    for(int i = 0; i < A.size(); i++) right[i] = A.size() - i;
		
    for(int i = 0; i < A.size(); i++){
      // for previous less
      while(!in_stk_p.empty() && in_stk_p.top().first > A[i]) in_stk_p.pop();
      left[i] = in_stk_p.empty()? i + 1: i - in_stk_p.top().second;
      in_stk_p.push({A[i],i});
			
      // for next less
      while(!in_stk_n.empty() && in_stk_n.top().first > A[i]){
        auto x = in_stk_n.top();in_stk_n.pop();
        right[x.second] = i - x.second;
      }
      in_stk_n.push({A[i], i});
    }

    int ans = 0, mod = 1e9 +7;
    for(int i = 0; i < A.size(); i++){
      ans = (ans + A[i]*left[i]*right[i])%mod;
    }
    return ans;
  }
};

