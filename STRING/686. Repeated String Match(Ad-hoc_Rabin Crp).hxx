
/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
Example 3:

Input: a = "a", b = "a"
Output: 1
Example 4:

Input: a = "abc", b = "wxyz"
Output: -1
Similar problems
Longest Substring with At Most K Distinct Characters
Buddy Strings
Form Largest Integer With Digits That Add up to Target
*/

/*
//Approach #1: Ad-Hoc [Accepted]
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 1;
        string s(A);
        while (s.size() < B.size()) {
            s += A;// every +repeat A one time, until size of A > size(B), make sure A repat the least amout of time
            i++;
        }
        if (s.find(B) != string::npos) return i;// if found, return position at i
        //else, repate A one more time, if found, return found position at i+1
        if ((s + A).find(B) != string::npos) return i + 1;
        
        return -1;// otherwise not found
    }
};
*/
/*
Complexity Analysis

Time Complexity: O(N*(N+M))O(N∗(N+M)), where M, NM,N are the lengths of strings A, B. We create two strings A * q, A * (q+1) which have length at most O(M+N). When checking whether B is a substring of A, this check takes naively the product of their lengths.

Space complexity: As justified above, we created strings that used O(M+N)O(M+N) space.*/
// Approach #2: Rabin-Karp (Rolling Hash) java version
import java.math.BigInteger;//

class Solution {
    public boolean check(int index, String A, String B) {
        for (int i = 0; i < B.length(); i++) {
            if (A.charAt((i + index) % A.length()) != B.charAt(i)) {
                return false;
            }
        }
        return true;
    }
    public int repeatedStringMatch(String A, String B) {
        int q = (B.length() - 1) / A.length() + 1;
        int p = 113, MOD = 1_000_000_007;
        int pInv = BigInteger.valueOf(p).modInverse(BigInteger.valueOf(MOD)).intValue();

// hash for strB
        long bHash = 0, power = 1;
        for (int i = 0; i < B.length(); i++) {
            bHash += power * B.codePointAt(i);
            bHash %= MOD;
            power = (power * p) % MOD;
        }
// hash for strA
        long aHash = 0; power = 1;
        for (int i = 0; i < B.length(); i++) {
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            power = (power * p) % MOD;
        }

        if (aHash == bHash && check(0, A, B)) return q;
        power = (power * pInv) % MOD;
//rolling hash as well as checking valid
        for (int i = B.length(); i < (q + 1) * A.length(); i++) {
            aHash -= A.codePointAt((i - B.length()) % A.length());
            aHash *= pInv;
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            if (aHash == bHash && check(i - B.length() + 1, A, B)) {
                return i < q * A.length() ? q : q + 1;
            }
        }
        return -1;
    }
}