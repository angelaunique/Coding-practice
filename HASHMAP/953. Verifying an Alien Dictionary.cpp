/*Palindrome Permutation
Find Duplicate File in System
Analyze User Website Visit Pattern

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).*/

class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] aplhabets = new int[26];
        for(int i=0; i<order.length(); i++){
            aplhabets[order.charAt(i)-'a'] = i;
        }
        
        for(int i=1; i<words.length; i++){
            if ( !inOrder(aplhabets, words[i-1], words[i]) ){
                return false;
            }
        }
        return true;
    }
    
    public boolean inOrder(int[] aplhabets, String word1, String word2){
        int one=0, two=0;
        while( one < word1.length() && two < word2.length() ){
            int onePosition = aplhabets[word1.charAt(one)-'a'];
            int secPosition = aplhabets[word2.charAt(two)-'a'];
            if ( onePosition > secPosition )
                return false;
            else if ( onePosition == secPosition ){
                one++;
                two++;
            } else{
                return true;
            }
        }
        if ( word1.length() > word2.length()  ) return false;
        
        return true;// if it came here, it means every case is true.
    }
}