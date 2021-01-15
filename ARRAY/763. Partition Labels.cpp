
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
 
//brute force
class Solution {
public:
     vector<int> partitionLabels(string S) {
         int start=0;
         int left=0;
         int right = 0;
         vector<int> ans;
        while(start<S.size()){
            int left=start;
            int right=start;
            while(left<=right && left<S.size()){
                int curr=right+1;    
                while(curr<S.size()){
                    if(S[left]==S[curr]){
                        right=max(right,curr);
                    }
                    curr++;
                }
                left++;
            }
            ans.push_back(right-start+1);
            start=left;
            }
        return ans;
    }
};
// brute force2
class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> ans;
      size_t start = 0;
      size_t end = 0;
      for (size_t i = 0; i < S.size(); ++i) {
        end = max(end, S.find_last_of(S[i]));
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};
//hashtable1
class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> last_index(128, 0);
      for (int i = 0; i < S.size(); ++i)
        last_index[S[i]] = i;
      vector<int> ans;
      int start = 0;
      int end = 0;
      for (int i = 0; i < S.size(); ++i) {//遍历循环找到s[i]最后出现的位置
        end = max(end, last_index[S[i]]);//s[i]最后出现的位置如果大于0的话需要扩充
        if (i == end) {//找到最大出现位置
          ans.push_back(end - start + 1);//切割
          start = end + 1;//切割完重新定起始位置
        }
      }
      return ans;
    }
};
//hashtable2
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        int last[26];
       
 For each letter encountered, process the last occurrence of that letter, extending the current partition [anchor, j] appropriately.
        for (int i = 0; i < S.length(); ++i)
            last[S[i] - 'a'] = i;
        int l = 0, r = 0;
        for(int i = 0; i < S.size(); i++) {
            r = max(r, last[S[i] - 'a']);//
            if (i == r) {//critical checking condition,If we are at the end of the partition (i == j) 
                result.push_back(r - l + 1);
                l = i + 1;
            } 
        }
        return result;
    }
};