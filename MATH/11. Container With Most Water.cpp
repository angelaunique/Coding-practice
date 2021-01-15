
/*
*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 */

/*
Approach 1: Brute Force
Algorithm

In this case, we will simply consider the area for every possible pair of the lines and find out the maximum area out of those.

*/
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int i = 0; i < height.size(); i++)
            for (int j = i + 1; j < height.size(); j++)
                maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
        return maxarea;
        
    }
};*/
/*
Approach 2: Two Pointer Approach
Algorithm
The intuition behind this approach is that the area formed between the lines will always be 
limited by the height of the shorter line. Further, the farther the lines, the more will be the area obtained.

We take two pointers, one at the beginning and one at the end of the array constituting the length 
of the lines. Futher, we maintain a variable \text{maxarea}maxarea to store the maximum area obtained till now. 
At every step, we find out the area formed between them, update \text{maxarea}maxarea and move the pointer 
pointing to the shorter line towards the other end by one step.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
       int maxarea = 0, l = 0, r = height.size() - 1;// l;  first element, r last element
        while (l < r) {// if first < last
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l)); // min(height[l], height[r]) 
            // take the shorter side of the two, * distance
            if (height[l] < height[r])// if left < right, left move toward
                l++;
            else
                r--;// lese if left > right, right move in
        }
        return maxarea;
    }
};