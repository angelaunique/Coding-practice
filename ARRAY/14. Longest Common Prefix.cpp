
/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/

//in java The indexOf() method returns the position of the first occurrence of specified character(s) in a string.
//in c++ :location = str1.find( "Omega", 0 );
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(auto s: strs) res = match(res, s);
        return res;
    }
    
    string match(const string& pre, const string& s){
        int i = 0, len = min(pre.size(), s.size());
        for(; i < len; i++) if(s[i] != pre[i]) break;
        return pre.substr(0, i);
    }
};
*/
// method 2 using sort
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());// sort alphabetically order 
/* after sort : flight, flow ,flower*/
        
     
        string a = strs[0], b = strs.back();
        int i = 0;// must be here, not in for loop! bc it's in return value at the end!
        for(  ; i < min(a.size(), b.size()); i++) if(a[i] != b[i]) break;
        return a.substr(0, i);//if none found, will return empty string
    }
};


/*
public class HelloWorld{
     public static void main(String[] args) {
    String myStr = "planet earth, you are a great planet.";
    System.out.println(myStr.indexOf("planet"));
  }
}
output 0
*/
/*
public class HelloWorld{
     public static void main(String[] args) {
    String myStr = "plan";
    System.out.println(myStr.indexOf("planet"));
  }
}
output 0*/
// java sol
class Solution {
     public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];// prefix = flower
    for (int i = 1; i < strs.length; i++)
        while (strs[i].indexOf(prefix) != 0) {// strs[1] = flow; strs[i].indexOf(prefix)  = flow.indexOf(flower)  = -1
            int idx = strs[i].indexOf(prefix) ;
            prefix = prefix.substring(0, prefix.length() - 1);//prefix = prefix.substring(0, 6- 1) =  prefix.substring(0,5) =flow
            if (prefix.isEmpty()) return "";
        }        
    return prefix;
    }
}
// java
/*
Imagine a very short string is at the end of the array. The above approach will still do SS comparisons. One way to optimize this case is to do vertical scanning.
//We compare characters from top to bottom on the same column (same character index of the strings) before moving on to the next column.
*/
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)// two conditions for vertical scan 
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}
// methodApproach 3: Divide and conquer
/*
Time complexity : O(S) , where S is the sum of all characters in all strings. In the worst case there will be n equal strings with length m
// and the algorithm performs S = m \cdot nS=m⋅n character comparisons.*/
// method 3 divide and conquer
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";    
        return longestCommonPrefix(strs, 0 , strs.length - 1);// because we need to find prex,thus start 
}

// recusion for divide+conquer
private String longestCommonPrefix(String[] strs, int l, int r) {
    if (l == r) {// base case 
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        String lcpLeft =   longestCommonPrefix(strs, l , mid);//divide
        String lcpRight =  longestCommonPrefix(strs, mid + 1,r);//divide
        return commonPrefix(lcpLeft, lcpRight);// this function is to find common prefix--conquer
   }
}
// method to conquer
String commonPrefix(String left,String right) {
    int min = Math.min(left.length(), right.length());       
    for (int i = 0; i < min; i++) {
        if ( left.charAt(i) != right.charAt(i) )
            return left.substring(0, i);
    }
    return left.substring(0, min);
    //a.substr(0, i);
}
//Approach 4: Binary search
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0)
        return "";
    int minLen = Integer.MAX_VALUE;
    for (String str : strs)
        minLen = Math.min(minLen, str.length());
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substring(0, (low + high) / 2);
}

private boolean isCommonPrefix(String[] strs, int len){
    String str1 = strs[0].substring(0,len);
    for (int i = 1; i < strs.length; i++)
        if (!strs[i].startsWith(str1))
            return false;
    return true;
}
/*In the worst case we have nn equal strings with length mm

Time complexity : O(S \cdot \log m)O(S⋅logm), where SS is the sum of all characters in all strings.

The algorithm makes \log mlogm iterations, for each of them there are S = m \cdot nS=m⋅n comparisons, which gives in total O(S \cdot \log m)O(S⋅logm) time complexity.

Space complexity : O(1)O(1). We only used constant extra space.
*/
// Trie
public String longestCommonPrefix(String q, String[] strs) {
    if (strs == null || strs.length == 0)
         return "";  
    if (strs.length == 1)
         return strs[0];
    Trie trie = new Trie();      
    for (int i = 1; i < strs.length ; i++) {
        trie.insert(strs[i]);
    }
    return trie.searchLongestPrefix(q);
}

class TrieNode {

    // R links to node children
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    // number of children non null links
    private int size;    
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
        size++;
    }