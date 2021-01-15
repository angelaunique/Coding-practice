/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
Each element of candidate is unique.
1 <= target <= 500

*/
//看原题backtrack树图

class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates, int target, vector <int> path, int idx) {
         if(target < 0) return;
         if(target == 0) {
             ans.push_back(path);
             return;
         }
           
         for(int i=idx;i<candidates.size();i++) {
             int elem = candidates[i];
             
             path.push_back(elem); //every step put inside
             
                f(candidates, target - elem, path, i);
            
             path.pop_back();//here, path need to claer when return back!!!
         }
         
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> path;
       // for(int i=idx;i<candidates.size();i++) // Don't need this for loop! because,the tree grows inside of the recursion! 
        f(candidates, target, path, 0);
        
        return ans;
    }
};