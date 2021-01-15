// C++ CONTAINER Video

// https://www.youtube.com/watch?v=IaTzi_bsuJU 
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


// set library: http://www.cplusplus.com/reference/set/set/insert/
// method1 use set
#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window use while loop to combine two for loops
        if (s.size() == 0) return 0;
        int i = 0, j = 0
        int maxsize = 0;//maxsize to update count of different substring
        int size = s.size();
        set<char> set;
        //OR unordered_set<char> set;
        while( i < size && j < size){
            if(set.count(s[j])==0){  
                set.insert(s[j]);// or set.add(s[j++])
                j++;
                maxsize = max(maxsize, j - i);// since j start at o and there is a j++ in the previous line
            } else {
                set.erase(s[i]);
                i++;
           }
        }
        return maxsize;
     }   
};
//method 2 use hashmap
/*the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values, 
and keep two pointers which define the max substring. move the right pointer to scan through the string , 
and meanwhile update the hashmap. If the character is already in the hashmap, then move the left pointer to the 
right of the same character last found. Note that the two pointers can only move forward.*/
public:
    int lengthOfLongestSubstring(string s) {
       if (s.size()==0) return 0;  
       map<char, int> charMap;
       int maxLen=0, j=0;
       for (int i=0; i<s.size(); ++i){
           //OR if(charMap.count(s[i]) != 0){
           if (charMap.find(s[i]) != charMap.end()) { // == end, found
              // charMap.find(s[i])->second += 1;
                  j = max(j, charMap[s[i]]);
            }
            charMap[s[i] ]= i;
            maxLen = max(maxLen,i-j); // max is a function keyword, can't use max(max,j)
        }
        return maxLen; 
    }
};

// method 3, use vector as dictionary
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
// method4 dict
        vector<int> vect(128, -1);//must initialize with -1, otherwise empty string won't work: input" ", output: 0 expected 1
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (vect[s[i]] > start)
                start = vect[s[i]];
            vect[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// method 4 USE FACT total 128 charactors- array
class Solution {
public:
        int arr[128]={0};
        int i=0, j=0, count=0;
        
        while(j<s.size()){
            if(!arr[s[j]]){
                arr[s[j++]]++;
                count=max(j-i, count);
            }
            else{
                arr[s[i]]--;
                i++;
            }
        }
        return count;     