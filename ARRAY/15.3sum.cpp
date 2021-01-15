/*
15. 3Sum
Given an array n
Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
class Solution {
     
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort first to reduce k,j update cycles
        vector<vector <int>> vect; // must declare as [[]], vector in vector, otherwise can't push
        if (nums.size() < 3) return vect;
        
        for (int i = 0; i < nums.size(); i++) // i <  nums.size()-2 not nums.size()!!
        {
                // all numbers from now on will be greater than 0, no point in continuing
		        if (nums[i] > 0) break; // duplicate for i 
                // we have seen this number & combo before; skip
		        if (i > 0 and nums[i] == nums[i-1]) continue;
            
                int j = i+1, k = nums.size()-1;
                int sum  = 0-nums[i];// IMPORTANT FOR DYNAMIC PROGRAMMING
                while(j <k ){
                    //vector<int>  v;  push triplet , don't need v
                    if( nums[j] + nums[k] == sum) {
                        vect.push_back({nums[i] ,nums[j] ,nums[k] }); // easier to push triplet
                    /*sort(v.begin(), v.end());
                    vector<vector <int>>::iterator it = find (vect.begin(), vect.end(), v); // iterator must also be vect in vect
                    if (it == vect.end()) // if not in vect, then push*/
                    // skip repeated value  {n}
                    while( j < k && nums[j] == nums[j+1])   j++; // j < k needed here since otherwise it's going to go outbound since there is an j update here, so need to catch the range
                    while( j < k && nums[k] == nums[k-1])   k--; // j < k needed here since otherwise it's going to go outbound, since there is an k update here, need to catch the range
                    j++;
                    k--;    
                    }
                  else if (nums[j] + nums[k] > sum){
                      k--;
                  } else {// AS WELL AS INCREMENT AND DECREMENT, while loop并行，减少一个o    
                // else sum !=0;
                j++;
                }     
            }           
        }
        return vect;
    } 
};


