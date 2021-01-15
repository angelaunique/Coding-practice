/*10. Regular Expression Matching
Hard

4692

746

Add to List

Share
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
//https://leetcode.com/problems/regular-expression-matching/discuss/304089/DP-Solution-using-c%2B%2B-with-some-explanation
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
// 倒叙dp 法
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        
        //use a array to save all the status
        bool Result[s.length()+1][p.length()+1];
      
        //the first one is both empty sub-string
        Result[0][0] = true;

        //in case of a*b*c* or a*b* etc.
        for(int j = 1; j < p.length()+1; j++)
        {
            if(p[j-1] == '*')
                Result[0][j] = Result[0][j-2];
            else
                Result[0][j] = false;
        }
        
        //sub-string s compare to empty string
        for(int i = 1; i < s.length()+1; i++)
            Result[i][0] = false;
        
        //calculate all the value in the table
        for(int i = 1; i < s.length()+1; i++)
        {
            for(int j = 1; j < p.length()+1; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    Result[i][j] = Result[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    Result[i][j] = Result[i][j-2];
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                        Result[i][j] = Result[i][j] | Result[i-1][j];
                }
                else
                    Result[i][j] = false;
            }
        }
        return Result[s.length()][p.length()];
    }
};

/*
We can solve the problem using recursion. We need the helper function to keep track of the current indices of the pattern and the string. The basic condition would be when pattern index reaches the end, then we will check if the string index has also reached the end or not.

Now we will check if the pattern current index matches the string current index character, this would be true either when the characters are equal i.e. s[i]==p[j] or if the p[j]=='.' since '.' can be replaced by any character.

If the next pattern character is '*' that means the current pattern character p[j] could occur 0 or infinite times. So, then there would be two possibility either we can take match the current pattern character with the string and move i by 1 or we can just take zero occurence of the current pattern character and move the pattern character by 2. We will apply the OR condition between these two conditions since if either of them matches then it solves our problem and if next pattern character is not '' , then we need to check if the current character matches or not and also move both string and pattern character by 1.

The time complexity of this brute force approach is O(3^(max(m,n)) and space complexity is O(max(m,n)) where m and n are the length of pattern and string respectively.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
    
    bool helper(string s, string p, int i, int j)
    {
        /* The basic condition would be when pattern index reaches the end, then we will check if the string index has also reached the end or not.*/
        if(j==p.length()) 
            return i==s.length();
        
        bool first_match=(i<s.length() && (s[i]==p[j] || p[j]=='.' )); // single char match 
        
        if(j+1<p.length() && p[j+1]=='*')
        {//or we can just take zero occurence of the current pattern character and move the pattern character by 2
            return (helper(s,p,i,j+2)|| (first_match && helper(s,p,i+1,j) ));
            // if j+1 is a '*' can just keep j the same, s move by 1, since what ever i+1 is, it will match first_match && helper(s,p,i+1,j) 
            // OR if if j+1 is a '*',if it represent zero, we can just jump it 
        }
        else// if p[j+1] = '.'
        {//move i by 1 
            return (first_match && helper(s,p,i+1,j+1));
        }
    }
};
/*
We are actually recomputing the solution for the same subproblems many times. So to avoid that we can initialize dp matrix with all values with being -1. Now if dp[i][j]>=0 then that means this has been already computed so we can return the results here only, thus, it saves time and we don't need to recompute that again. Notice that we are saving the results in dp[i][j] in the second last line and this result would always be positive either 0 or 1.

The time complexity is now O(mn) and space complexity is O(mn) where m and n are the length of pattern and string respectively.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length(),-1));
        return helper(s,p,0,0,dp);
    }
    
    bool helper(string s, string p, int i, int j,vector<vector<int>> &dp)
    {
        if(j==p.length())
            return i==s.length();
        if(dp[i][j]>=0)
            return dp[i][j];
        bool first_match=(i<s.length() && (s[i]==p[j] || p[j]=='.' ));
        bool ans=0;
        if(j+1<p.length() && p[j+1]=='*')
        {
            ans= (helper(s,p,i,j+2,dp)|| (first_match && helper(s,p,i+1,j,dp) ));
        }
        else
        {
            ans= (first_match && helper(s,p,i+1,j+1,dp));
        }
        dp[i][j]=ans;
        return ans;
    }
};
/*
Bottom up solution

We can derive the bottom up solution from top down approach only. We will make the matrix of length (s.length()+1)* (p.length()+1) . dp[s.length()][p.length()]=1 since both have ended at that point.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[s.length()][p.length()]=1;
        
        for(int i=s.length();i>=0;i--) ////二重循环后退的原因是dp[i][j]  depend on dp[i+1][j+1],所以 dp[i+1][j+1]必须先计算出来dp[i][j]才可以继续，否则就可以正向进行
        {
            for(int j=p.length()-1;j>=0;j--) // j is one less than i!
            {
                bool first_match=(i<s.length() && (p[j]==s[i]|| p[j]=='.'));
                    if(j+1<p.length() && p[j+1]=='*')
                    {
                        dp[i][j]=dp[i][j+2] || (first_match && dp[i+1][j]);
                    }
                else
                {
                    dp[i][j]=first_match && dp[i+1][j+1];
                }
            }
        }
        
    return dp[0][0];
    }
};

logo
Explore
Problems
Mock
Contest
Discuss
Store
0
Description
Solution
Discuss (999+)
Submissions
Back
Recursive Solution with Explanation - 2 ms, faster than 98.88%
0
cpinjala's avatar
cpinjala
7
April 22, 2019 7:43 PM

187 VIEWS
//Recursive Solution with Explanation - 2 ms, faster than 98.88%
class Solution {
    // For each character index in the text (i.e. i) and pattern (i.e. j), we do the following:
    //
    //  (1) If [j + 1] is '*' then we have following two options.
    //
    //      (a) Matches zero characters in the text. We call recursively by passing the complete input text (as zero
    //          characters matched) and removing first two characters from the pattern (since '.*' matches zero
    //          characters, it is as if the value '.*' is not present) i.e. (text, pattern.subString(2)). If this call
    //          returns true, we return true.
    //
    //      (b) Matches one or more characters in the text. If the character in the text[i] matches the character in
    //          pattern[j] or if the current pattern character is '.', then we work on the remaining part of the text by
    //          calling (text.subString(1), pattern). We will pass all of the pattern because '*' can consume more of
    //          the text characters as this case is one or more characters are consumed by '.*' or '<char>*'. If this
    //          call returns true, we return true
    //
    //      (c) else we return false
    //
    //  (2) If current character in pattern[j] is '.' or if the current character in text[i] is equal to the
    //      character in pattern[j], then we work on the remaining part of the text and pattern by calling (text
    //      .subString(1), pattern.subString(1)). Return the value from this call.
    //
    public static boolean isMatch(String text, String pattern) {
        Boolean[][] dp = new Boolean[text.length()][pattern.length()];
        return isMatchUtil(text, pattern, 0, 0, dp);
    }

    // Different test cases:
    //
    // 1. (text = "aa", p = "a"): False => Pattern length less than Text
    // 2. (text = "a", p = "aa"): False => Text length less than Pattern
    // 3. (text = "bcd", p = "a*bcd"): True => Pattern '*' consumes Zero Length Text
    // 4. (text = "a", p = "a*"): True => Pattern '*' consumes entire Text
    // 5. (text = "", p = ".*"): True
    // 6. (text = "", p = "a*.*"): True
    // 7. (text = "ab", p = ".*"): True
    private static boolean isMatchUtil(String text, String pattern, int textIdx, int patternIdx, Boolean[][] dp) {

        if (patternIdx == pattern.length()) {
            // Test Case 1. (text = "aa", p = "a"): False => Pattern length less than Text
            return textIdx == text.length();
        }

        if (textIdx == text.length()) {

            if (isPatternMatchZeroCharacters(pattern, patternIdx)) {
                // 4. (text = "a", p = "a*"): True => Pattern '*' consumes entire Text
                // 5. (text = "", p = ".*"): True
                // 6. (text = "", p = "a*.*"): True
                return true;
            }
            // Test Case 2. (text = "a", p = "aa"): False => Text length less than Pattern
            return false;
        }

        if (dp[textIdx][patternIdx] != null) {
            return dp[textIdx][patternIdx];
        }

        if (patternIdx <= pattern.length() - 2 && pattern.charAt(patternIdx + 1) == '*') {
            // Test Case 3. (text = "bcd", p = "a*bcd"): True => Pattern '*' consumes Zero Length Text
            // First we try this option.
            if (isMatchUtil(text, pattern, textIdx, patternIdx + 2, dp)) {
                dp[textIdx][patternIdx] = true;
                return true;
            }

            // Test Case 4. (text = "a", p = "a*"): True => Pattern '*' consumes entire Text
            // Test Case 7. (text = "ab", p = ".*"): True
            //
            // If we were not successful for the option where '*' matches zero characters, we will try where it tries
            // to match one ore more occurrences. So, we should not have 'else if'. Instead it should be simple 'if'.
            if (pattern.charAt(patternIdx) == '.' || text.charAt(textIdx) == pattern.charAt(patternIdx)) {
                // consume as many characters as we can
                if (isMatchUtil(text, pattern, textIdx + 1, patternIdx, dp)) {
                    dp[textIdx][patternIdx] = true;
                    return true;
                }
            }
            // In the following case will cause to return false
            //
            //      ( "aab", "b*", 0, 4 )
            //
            dp[textIdx][patternIdx] = false;
            return dp[textIdx][patternIdx];
        }

        if (pattern.charAt(patternIdx) == '.' || pattern.charAt(patternIdx) == text.charAt(textIdx)) {
            if (isMatchUtil(text, pattern, textIdx + 1, patternIdx + 1, dp)) {
                dp[textIdx][patternIdx] = true;
                return dp[textIdx][patternIdx];
            }
        }
        dp[textIdx][patternIdx] = false;
        return dp[textIdx][patternIdx];
    }

    private static boolean isPatternMatchZeroCharacters(String pattern, int patternIdx) {
        // if a single character comes as input.
        if (patternIdx == pattern.length() - 1) {
            return false;
        }

        for (int idx = patternIdx; idx < pattern.length(); idx += 1) {
            if (idx + 1 == pattern.length()) {
                return false;
            }
            if (pattern.charAt(idx + 1) != '*') {
                return false;
            }
            idx++;
        }

        return true;
    }
}

    public static void main(String[] args) {
        {
            String text = "a";
            String pattern = ".*..a*";
            System.out.println("Expected False, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "aab";
            String pattern = "c*a*b*";
            System.out.println("Expected True, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "";
            String pattern = ".*";
            System.out.println("Expected True, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "ab";
            String pattern = ".*";
            System.out.println("Expected True, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "a";
            String pattern = "ab*";
            System.out.println("Expected True, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "";
            String pattern = "c*c*";
            System.out.println("Expected True, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "aa";
            String pattern = "a";
            System.out.println("Expected False, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "ab";
            String pattern = ".*c";
            System.out.println("Expected False, Actual: " + isMatch(text, pattern));
        }

        {
            String text = "aaa";
            String pattern = "aaaa";
            System.out.println("Expected False, Actual: " + isMatch(text, pattern));
        }
    }

dynamic programming
recursion
dynamic-programming
Comments: 0
BestMost VotesNewest to OldestOldest to Newest
Type comment here... (Markdown is supported)

Preview

Post
Copyright © 2020 LeetCode
Help Center
Jobs
Bug Bounty
Students
Terms
Privacy Policy
United StatesUnited States
Type here...(Markdown is enabled)
​
Saved

// 往前移动+倒叙
/*
Just to build a DP table checked, where checked[i][j] indicates whether s[0..i-1] matches with p[0..j-1]. The recursive relationship is as below:
To match with the empty string s[0..0] (i.e. to make checked[0][j]), P[0..j-1] has to meet: p[j-1]=='*' (to cancel p[j-2]) and checked[0][j-2] == true;
To match with the string s[0..i-1] (i.e. to make checked[i][j]), P[0..j-1] has to meet:

if p[j-1] =='*', then j must be larger than 1 (j>1) and
checked[i][j-2] (i.e. p[j-2] cancelled by '*')
checked[i-1][j] && (s[i-1] ==p[j-2] || p[j-2] =='.') (s[i-1] matches with p[j-2] or '.', )
if p[j-1] !='*', checked[i-1][j-1] && (s[i-1] ==p[j-1] || p[j-1] =='.')(i.e. s[i-1] matches with p[j-1] or '.')
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int i=2;i<=m;i+=2)
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=dp[0][i-2];
                dp[0][i-1]=dp[0][i-2];
            }
            else
            {
                dp[0][i]=0;
                dp[0][i-1]=0;
            }
            
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                    {
                        dp[i][j] = dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1]||dp[i][j-2];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
    }
};