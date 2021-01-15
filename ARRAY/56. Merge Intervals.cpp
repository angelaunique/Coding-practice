/*56. Merge Intervals
Medium

5020

317

Add to List

Share
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 
*/
intervals[i][0] <= intervals[i][1]

class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size()<=1) return intervals;
            sort(intervals.begin(), intervals.end());// default by element[0], beginning indec
            vector<vector<int>> output;
            output.push_back(intervals[0]);// push in the first one 
        
            for(int i=1; i<intervals.size(); i++) {
                if(output.back()[1] >= intervals[i][0])
                    output.back()[1] = max(output.back()[1] , intervals[i][1]);// change the first intervzal
                else output.push_back(intervals[i]); //if can't be merged, add to result vector
            }
            return output;
    }
};