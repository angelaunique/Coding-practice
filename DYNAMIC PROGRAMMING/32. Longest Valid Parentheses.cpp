/*32. Longest Valid Parentheses
Hard

3860

147

Add to List

Share
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
/* sample code from problem 300
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
        if (r == 0) return 1;
        if (f_[r] > 0) return f_[r];
        int ans = 1; // key!!
        for(int i = 0; i < r; ++i)
            if (nums[r] > nums[i])
                ans = max(ans, LIS(nums, i) + 1);
        f_[r] = ans;
        return f_[r];
    }
};
*/




// method 1 Recursion version, exceed time limit

class Solution { 
public:
    int longestValidParentheses(string s) {
        int ans = 0;  // can't initialize to -1! "" will return -1, should be 0
        
        for (int i = 1; i < s.length(); i++)       
            ans = max(recur(i,s) ,ans);
        return ans; 
        
    }  
    int recur(int i, string s) {
        int ret = 0;
        if (i <= 0)
                return 0;
        if (s[i] == ')'){
            
                if (s[i-1] == '(')
                    //(i >= 2 ? dp[i - 2] : 0) + 2;
                    ret = (i >= 2 ? recur(i - 2,s):0) + 2;// must check i >= 2  condition
                else{
                    int len = recur(i-1,s);
                    if(i - len - 1 >= 0 && s[i - len - 1] == '(')
                        ret = (i - len >= 2 ? recur(i - len - 2,s):0) + len + 2;// must check i >= 2  condition
                    }
                }
        return ret;                 
    }    
};


// method 2recursion with memory, still time limit since if there are 1000 of '(', memory is not used at wll
class Solution { 
public:
    int longestValidParentheses(string s) {
        int ans = 0;  // can't initialize to -1! "" will return -1, should be 0
        int n = s.length();
        if (n == 0) return 0; 
        f_ = vector<int>(n, 0); 
        for (int i = 1; i < s.length(); i++)       
            ans = max(recur(i,s) ,ans); // ans inside of ans has value recur(i - 2,s)+2 vs  recur(i,s) 
        return ans; 
        
    }
private:
    vector<int> f_ ;    
    int recur(int i, string s) {
        int ret = 0;
        if (i <= 0)
                return 0;
        if (f_[i] > 0) return f_[i];//
        
        int ans = 0;//
        if (s[i] == ')'){
            
                if (s[i-1] == '('){
                    ret = (i >= 2 ? recur(i - 2,s):0) + 2;// must check i >= 2  condition
                     ans = max(ret ,ans);//compare recur(i-2,s)+2 vs recur(i-4,s)+4....
                }
                else{
                    int len = recur(i-1,s);
                    if(i - len - 1 >= 0 && s[i - len - 1] == '(')
                        ret = (i - len >= 2 ? recur(i - len - 2,s):0) + len + 2;// must check i >= 2  condition
                        ans = max(ret ,ans);
                    }
                }
        f_[i] = ans;
        return f_[i];                 
    }    
};


// method3,  dp with memoization

class Solution {
public:
    int longestValidParentheses(string s) {
        vector <int> dp(s.length(),0);// NEED to initialize to 0 here, can't initialize to -1, will change calculate value!
        int ans = 0;
        //for( int i = s.length()-1; i >=0; i--) { 
        for (int i = 1; i < s.length(); i++) { // need to go forward , can't go backward 
               if (s[i] == ')'){            
                    if (s[i-1] == '('){
                        //dp[i] =  dp[i - 2]  + 2; not working, must check for i>=2 condition
                        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                    }else if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
                            dp[i] = ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2; //")(()())" this case covered by dp[i - dp[i - 1] - 2] is valid ,by this line
                            //dp[i] = dp[i - 1] +  dp[i - dp[i - 1] - 2]  + 2;//not working, must check for i>=2 condition
                        }
                    ans = max(ans,dp[i]);                        
                }
            }
        return ans;
      }
};

*/
/* Not sure how it works,another version of DP, generalize to i - dp[i] - 1 case, but combine all the conditions and each time move forward
 if (s[i] == ')' && i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
 caculate  dp[i + 1]
*/
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')' && i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(') {
                dp[i + 1] = dp[i] + dp[i - dp[i] - 1] + 2;
            }
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};*/
/*
// stack method
public class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> st = new Stack<>();
        st.push(-1);//"(()())" 
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {//s,-1; s:((
                st.push(i);//s:-1
            }
            else { // else if it's a ")",pop, if empty after pop
                    st.pop();//s pop whenever there is a ) appears
                    if (st.empty()) {
                        st.push(i);}//(
                    else{    
                    maxans = Math.max(maxans, i - st.peek());//st.peek()) return a number
                        }
            }
        }
        return maxans;
    }  
}
//Approach 4: Without extra space--preferred method!!
/*
Algorithm

In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string from the left towards the right and for every \text{‘(’}‘(’ encountered, we increment the leftleft counter and for every \text{‘)’}‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.

Next, we start traversing the string from right to left and similar procedure is applied.
*/
/*
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
*/