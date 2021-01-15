
/*
475. Heaters
Easy

779

889

Add to List

Share
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
 

Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.*/
/*class Solution {
public:

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int minRadius = 0;
    for (int i = 0; i < houses.size(); i++) {
    	// search for the closest heater whose position is at least the current house's position
    	auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
    	int curRadius = INT_MAX;
    	// if there is such a heater, update the radius for that heater to cover this house if necessary
    	if (larger != heaters.end())
    	    curRadius = *larger - houses[i];
    	// if the heater we found is not the first one, then the previous heater is the closest heater
    	// whose position is smaller than the current house's position
    	if (larger != heaters.begin()) {
    	    auto smaller = larger - 1;
    	   // the heater with the smaller required radius to cover the house wins
    	    curRadius = min(curRadius, houses[i] - *smaller);
    	}
    	minRadius = max(minRadius, curRadius);
    }
    return minRadius;
}
    
   */ 
class Solution {
public:
/*
Example:    h = house,  * = heater  M = INT_MAX

        h   h   h   h   h   h   h   h   h    houses
        1   2   3   4   5   6   7   8   9    index
        *           *       *                heaters
                
        0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
        0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

        0   1   1   0   1   0   1   2   3    (res = minimum of above two)

重要理解点！Result is maximum value in res, which is 3!!!!!
*/
    int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(), A.end());
        sort(H.begin(), H.end());
        vector<int> res(A.size(), INT_MAX); 
        
        // For each house, calculate distance to nearest RHS heater
        for (int i = 0, h = 0; i < A.size() && h < H.size(); ) { //从左往右扫，找与右边最近heater的距离， heater 大，h-a
            if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
            else { h++; }
        }
        
        // For each house, calculate distance to nearest LHS heater
        for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
            if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }// 从右往左，找与左边heater的距离,house值大，a-h
            else { h--; }
        }
       
        return *max_element(res.begin(), res.end());
    }
};