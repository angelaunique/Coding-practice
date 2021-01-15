/*
204. Count Primes
Easy

2279

651

Add to List

Share
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/

// Author: Huahua
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        vector<unsigned char> f(n, 1);
        f[0] = f[1] = 0;
        for(long i=2;i<=sqrt(n);++i) {// prime of n can't exceed sqrt(n)
            if(!f[i]) continue;
            for(long j=i*i;j<n;j+=i)
                f[j] = 0;
        }
        
        int ans = accumulate(f.begin(), f.end(), 0);// count number of one's
        return ans;
    }
};
