
/*
5. Longest Palindromic Substring
Medium

7351

554

Add to List

Share
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
// method 0 brute force
string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) return s;
        string res;
        int maxlen = 0;
        for(int i = 0; i < s.size() - maxlen; i++){
            for(int j = s.size() - 1; j >= i + maxlen; j--){
                if(s[j] != s[i]) continue;
                string str = s.substr(i, j - i + 1);
                if(isPalindrome(str) && str.size() > maxlen){
                    maxlen = str.size();
                    res = str;
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string s){
        if(s.size() == 0 || s.size() == 1) return true;
        int i(0), j(s.size() - 1);
        while(s[i] == s[j] && i < j) i++, j--;
        return i >= j;
    }

// method1 expand around centre
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++) {
            int len = max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i+1));
            if(len > (end-start)) {
                start = i - ((len-1)/2);
                end = i + (len/2);
            }
        }
        return s.substr(start, end-start+1);
    }
    
    int expandAroundCenter(string s, int left, int right) {
        if(s.length()==0 || left>right) return 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) left--, right++;
        return right-left-1;
    }
};
// method2 dynamic programming bottorm up
/*
The gist of the problem remains the same. dp[i, j] represents whether s[i, j] is a palindrome or not.
Base conditions for dp[i, j] to be true:

s[i] == s[j]
dp[i + 1, j - 1] is true 

otherwise
P(i,j)=(P(i+1,j−1) and Si==Sj)
*/
string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int n = s.size();
        int table[n][n];
    
        memset(table,-1,sizeof(table)); //Initializing table with -1
    
       //Filling up the table
        for (int i = 0; i < n; ++i) 
            table[i][i] = 1;  
    
     //checking for substring of length 2.
        int maxLen = 1;//actually maxLen= end-start+1
        int start = 0; 
        for (int i = 0; i < n - 1; ++i) { //checking for substring of length 2.
            if (s[i] == s[i + 1]) { 
                table[i][i + 1] = 1; 
                start = i;  //Updating the start
                maxLen = 2; 
            } 
        }
        for(int k=3;k<=n;k++){ //Checking for length greater than 2 and k is length of substring 
            for(int i=0;i<n - k + 1;i++){
                int j = i + k - 1; //Initializing the end Index i.e j = i + k - 1
                if(table[i+1][j-1] == 1 && s[i] == s[j]){ //Checking for the conditions i.e checking for sub-string from ith index to jth index.
                    table[i][j] = 1;
                    if (k > maxLen) { //Updating the maxLen
                        start = i;  //Updating the start
                        maxLen = k; //
                    } 
                }
            }
        }
        return s.substr(start, maxLen);
    }


/*  Dynamic programming
We can use dynamic programming to solve this problem. So, we know that in any string there would be atleast palindrome of length 1, so we can just initialize all the diagonal elements with true. dp[i][j] represents if the string starts from ith index and ends in jth index (inclusive) , if it is true then that string that is starting from i and ending in j is a palindrome. and vice versa.

For string of length 2, if s[j]==s[j+1], then that must be a palindrome so we can set that to true.

For string length greater than 2, it should satisfy two conditions one that the start index j and end index j+len-1 characters at that should be equal and also string starting from j+1 and ending in j+len-2 should also be a palindrome which is equal to dp[j+1][j+len-2].
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string p;
        if(s.length()==0)
            return p;
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        for(int i=0;i<s.length();i++)
            dp[i][i]=1; // base case1, len = 1
        int start=0, end=0;
        
        for(int len=2;len<=s.length();len++)
        {
            for(int j=0;j+len<=s.length();j++)
            {
                if(len==2) // base case2, len = 2
                {
                    dp[j][j+1]=(s[j]==s[j+1]);
                }
                else
                {
                    dp[j][j+len-1]=(s[j]==s[j+len-1] && dp[j+1][j+len-2]); // dp[j][j+len-1] is true if two condition is satisfied 
                }
                if(dp[j][j+len-1]) // only change start and end when dp[j][j+len-1] is palindrome
                {
                    start=j;// increase start 
                    end=j+len-1;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
// method 1  dp with while loop
 string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        if(n==1)
            return s;
        int left,right,maxlen=0,templen,ansindex;
        int centre=0;
        while(centre<n)
        {
            left=right=centre;
            while(right<n-1&&s[right]==s[right+1])
                right++;
            centre=right+1;
            while(left>0&&right<n-1&&s[left-1]==s[right+1])
            {
                left--;
                right++;
            }
            templen=right-left+1;
            if(templen>maxlen)
            {
                maxlen=templen;
                ansindex=left;
            }   
        }
        return (s.substr(ansindex,maxlen));
    }



//Approach 5: Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        if( s.size() <= 1 ) return s;
        
        string d( 2 * s.size() + 1, '#' ); // This has to 2x + 1 of string 's'
        for( int j = 0 ; j < s.size() ; ++ j ) d[ 2 * j + 1 ] = s [ j ];
        vector< int > l( d.size(), 0 );
        int center = 0;
        int right = 0;
        int maxIdx = 0;
        
        for( int i = 1 ; i < d.size() ; ++i ) {
            // will be negative only when i = 1. The following 'if' prevents from accessing out of bounds.
            int mirror = 2 * center - i; 
            if( i < right ) l [ i ] = min( l[ mirror ], right - i );
            
            // Expand with the current length
            int start, end;
            start = i - l[ i ] - 1;
            end = i + l[ i ] + 1;
            while( start >= 0 && end < d.size() && d[ start-- ] == d[ end++ ] ) l[ i ]++;

            if( i + l[ i ] > right ) {
                right = i + l[ i ];
                center = i;
            }
            if( l[ i ] > l[ maxIdx ] ) {
                maxIdx = i;
            }
        }
        // Since the above computation is based upon the transformed string 'd', extract the substr from 'd'
        s = d.substr( maxIdx - l[ maxIdx ], 2 * l[ maxIdx ] + 1 );
        string res;
        for( int i = 0 ; i < s.size() ; ++i ) {
            if( s[ i ] != '#' ) res.push_back( s[ i ] );
        }
        
        return res;
    }
    
};