https://www.youtube.com/watch?v=YN0mGjMX8Bo&t=332s
/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

// backtracking!
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;// return result
        if(s.empty()) return ret;
        
        vector<string> path;// vector string
        dfs(0, s, path, ret); // index, string, result inner vector string, final vecotor[[]]
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));// right side exculsive!
                dfs(i+1, s, path, ret);// i(index) increase to keep proping to find longer palindrome
                path.pop_back(); // clear path, for adding next valid sol
            }
        }
    }
    
   bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }  
    
};