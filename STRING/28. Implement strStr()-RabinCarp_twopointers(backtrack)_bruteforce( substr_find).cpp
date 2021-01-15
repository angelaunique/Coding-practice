/*Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().*/
/*Approach 1: Substring: Linear Time Slice
Drawback of the previous algorithm is that one compares absolutely all substrings of length L with the needle. There is no need to that.

class Solution {
public:
    int strStr(string haystack, string needle) {
        
     int L = needle.size(), n = haystack.size();

    for (int start = 0; start < n - L + 1; ++start) {
      if (haystack.substr(start, L) == needle) {
        return start;//substr: second parameter is length of substring
      }
    }
    return -1;
  }
};
*/

/*
class Solution {
public:
    int strStr(string haystack, string needle) {

    return haystack.find(needle);
      }
};*/
/*
//Approach 2: Two Pointers: Linear Time Slice, backtrack!
class Solution {
public:
    int strStr(string haystack, string needle) {
    int L = needle.size(), n = haystack.size();
    if (L == 0) return 0;

    int pn = 0;
    while (pn < n - L + 1) {// This while loop for backtracking
          // find the position of the first needle character
          // in the haystack string
          while (pn < n - L + 1 && haystack[pn] != needle[0]) ++pn;
         // pn is pointer for hay starts at 0, while loop find until the first match cjar
          // compute the max match string
          int currLen = 0, pL = 0;//pl is pointer for needle// PL also reset by backtracking

          // below while loop check one by one if the substr the same
          while (pL < L && pn < n && haystack[pn] == needle[pL]) {
            ++pn;
            ++pL;
            ++currLen;
          }

          // if the whole needle string is found,
          // return its start position
          if (currLen == L) return pn - L;

          // otherwise, backtrack
          pn = pn - currLen + 1;
                 
                 5-4+1 =2 hat we move pn pointer back to the position pn = pn - curr_len + 1, and not to the position pn = pn -                            curr_len, since this last one was already investigated.
             }
    return -1;    
         
    }
};
*/
/*Approach 3: Rabin Karp: Constant Time Slice
Let's now design the algorithm with \mathcal{O}(N)O(N) time complexity even in the worst case. The idea is simple: move along the string, generate hash of substring in the sliding window and compare it with the reference hash of the needle string.

There are two technical problems:

How to implement a string slice in a constant time?
String slice in a constant time

Strings are immutable in Java and Python, and to move sliding window in a constant time one has to convert string to another data structure, for example, to integer array of ascii-values.
Rolling hash: hash generation in a constant time

To generate hash of array of length L, one needs \mathcal{O}(L)O(L) time.
Since one deals here with lowercase English letters, all values in the integer array are between 0 and 25 : arr[i] = (int)S.charAt(i) - (int)'a'.
So one could consider string abcd -> [0, 1, 2, 3] as a number in a numeral system with the base 26. Hence abcd -> [0, 1, 2, 3] could be hashed as
*/
class Solution {
public:
    int charToInt(int idx, string s) {
    return (int)s[idx] - (int)'a';
  }

    int strStr(string haystack, string needle) {
     int L = needle.size(), n = haystack.size();
    if (L > n) return -1;

    // base value for the rolling hash function
    int a = 26;
    // modulus value for the rolling hash function to avoid overflow
    long modulus = (long)pow(2, 31);

    // compute the hash of strings haystack[:L], needle[:L]
    long h = 0, ref_h = 0;
    for (int i = 0; i < L; ++i) {
      h = (h * a + charToInt(i, haystack)) % modulus;// hay//charToInt(i, haystack) fof single digit
        //h(0) = 0*26+1 % modulus 以上公式由h0开始一步一步狄忒到总结
        //h1 = (0*26+1 )*26+2
        //h2 = ((0*26+1 )*26+2)*26 +3=s6^(l-1)
      ref_h = (ref_h * a + charToInt(i, needle)) % modulus;//needle同以上
    }
    if (h == ref_h) return 0;

    // const value to be used often : a**L % modulus
    long aL = 1;
    for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;

    for (int start = 1; start < n - L + 1; ++start) {
      // compute rolling hash in O(1) time
      h = (h * a - charToInt(start - 1, haystack) * aL
              + charToInt(start + L - 1, haystack)) % modulus;// 总结到移动公式
      if (h == ref_h) return start;
    }
    return -1;
  }
};
