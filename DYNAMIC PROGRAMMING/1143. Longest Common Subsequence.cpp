/*1143. Longest Common Subsequence
Medium

1888

25

Add to List

Share
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.*/

/*The first step is to find a way to recursively break the original problem down into subproblems. We want to find subproblems such that we can create an optimal solution from the results of those subproblems.
Approach 3: Dynamic Programming
 the largest subproblem is the one we start with, and the smallest subproblems are the ones with just one letter left in each word. The answer for each subproblem depends on the answers to some of the smaller subproblems.

*/
//method1 move forward-recursion 
class Solution {
public:
    
	// Memorization table for reusing precalculated result
  
    int LCSubSeq(string &s1, string &s2, int id1, int id2)
    {
       
        
        if(s1[id1]==s2[id2])
        {
            // If there is a match we add 1 and move forward in 
            // both string s1 and s2 => (s1,s2,i+1,j+1)
            // So we return 1 + dp[i+1][j+1]
            LCSubSeq[id1][id2] = 1 + LCSubSeq(s1,s2,id1+1,id2+1);   
        }
        else
        {
            // otherwise there are two possiblities of max LCS which are
            // moving forward either in s1 => (s1,s2,i+1,j) or
            // moving forward in s2 => (s1,s2,i,j+1). We take the max from them
            // So, we return max(dp[i+1][j],dp[i][j+1])
            LCSubSeq[id1][id2] = max(LCSubSeq(s1,s2,id1+1,id2),LCSubSeq(s1,s2,id1,id2+1));
        }
        return  LCSubSeq[id1][id2];
    }
// method2 move forward-recursion with memoization
class Solution {
public:
    
	// Memorization table for reusing precalculated result
    int dp[1001][1001];
	
    int LCSubSeq(string &s1, string &s2, int id1, int id2)
    {
        if(id1>=s1.length() || id2>=s2.length()) return 0;
        
        // return already calculated value
        if(dp[id1][id2]!=-1) return dp[id1][id2];
        
        if(s1[id1]==s2[id2])
        {
            // If there is a match we add 1 and move forward in 
            // both string s1 and s2 => (s1,s2,i+1,j+1)
            // So we return 1 + dp[i+1][j+1]
            dp[id1][id2] = 1 + LCSubSeq(s1,s2,id1+1,id2+1);   
        }
        else
        {
            // otherwise there are two possiblities of max LCS which are
            // moving forward either in s1 => (s1,s2,i+1,j) or
            // moving forward in s2 => (s1,s2,i,j+1). We take the max from them
            // So, we return max(dp[i+1][j],dp[i][j+1])
            dp[id1][id2] = max(LCSubSeq(s1,s2,id1+1,id2),LCSubSeq(s1,s2,id1,id2+1));
        }
        
        return dp[id1][id2];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp,-1,1001*1001*sizeof(int));
        return LCSubSeq(text1,text2,0,0);
    }
};
// method3 move forward-dp-bottom up

class Solution {
public:
    
	// Memorization table for reusing precalculated result
    int dp[1001][1001];
	
    int LCSubSeq(string &s1, string &s2, int id1, int id2)
    {
        int n = text1.size();
        int m = text2.size();
        int t[n+1][m+1]; // create matrix
    
        // initialize matrix to all 0's
        for (int id1 = 0; id1<n+1;id1++){
            for (int id2 = 0; id2 <m+1; id2++){
                if (id2 == 0 || id2 == 0){
                    t[id2][id2] = 0;
                }
            }
        }
        // go through the dp matrix 
        for (int id1 = 1; id1<n+1; id1++){ //watchout ,it is n+1 and m+1 here!
            for (int id2 = 1; id2<m+1; id2++){
                if (text1[id1-1] == text2[id2-1]){
                    t[id1][id2] = 1 + t[id1-1][id2-1];
                }else{
                    t[id1][id2] = max(t[id1-1][id2], t[id1][id2-1]);
                }
            }
        }
    
    
};

/**********************************************************************************************/
// method1: dp with move backward-recursion
class Solution {
public:
    
     int recursion(string x, string y, int n, int m){
         if (n == 0 || m == 0){
             return 0;
         }
        
         if (x[n-1] == y[m-1]){
             return 1+recursion(x, y, n-1, m-1);
         }else{
             return max(recursion(x, y, n-1, m), recursion(x, y, n, m-1));
         }
     }
// method2: dp with move backward-recursion with memoization    
    
    
     int memoization(string x, string y, int n, int m){
         if (n == 0 || m == 0){
             return 0;
         }
         if (t[n][m] != -1){ // memoization is here!
             return t[n][m];
         }
         if (x[n-1] == y[m-1]){
             return t[n][m] = 1+memoization(x, y, n-1, m-1);
         }else{
             return t[n][m] = max(memoization(x, y, n-1, m), 
                                  memoization(x, y, n, m-1));
         }
     }
    
    //  method3:backward directly convert to dp:botom up , for loop is forward
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        int t[n+1][m+1]; 
        // initialize matrix to all 0's
        for (int i = 0; i<n+1; i++){
            for (int j = 0; j<m+1; j++){
                if (i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }
        // go through the dp matrix 
        for (int i = 1; i<n+1; i++){
            for (int j = 1; j<m+1; j++){
                if (text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }