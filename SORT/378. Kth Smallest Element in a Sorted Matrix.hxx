/*378. Kth Smallest Element in a Sorted Matrix
Medium

2745

147

Add to List

Share
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.*/
// Author: Huahua
// Running time: 24 ms (beats 97.12%)
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r) {
      long m = l + (r - l) / 2;      
      int total = 0;
      int s = n;
      //看总共有多少个数小于等于m
      for (const auto& row : matrix)
        total += (s = distance(begin(row), upper_bound(begin(row), begin(row) + s, m)));
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
//method2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int rows = a.size();
        int cols = a[0].size();
        int start = a[0][0];
        int end = a[rows-1][cols-1];
        while(start<end) {
            int mid = (start+end)/2;
            int j = cols-1;
            int cnt = 0;
            for (int i = 0; i<rows; i++) {
                while(j>=0 and a[i][j] > mid) {//j = cols-1;
                    j--;
                }
                cnt += (j+1);
            }
            if (cnt < k) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};

 