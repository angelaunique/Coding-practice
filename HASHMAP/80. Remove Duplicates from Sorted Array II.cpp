/*
smilar problems:
Sum of Subarray Minimums
Minimum Cost to Move Chips to The Same Position
Minimum Time Visiting All Points

80. Remove Duplicates from Sorted Array II
Medium

1328

731

Add to List

Share
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

// This solution using map is my intuition array but nut modified on original array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums){mp[i]++;}
        nums.clear();
        
        for(auto &it: mp){
            int count = 0;
            for(int i = 0; i < it.second;i++){
                if(it.second >=2){
                    nums.push_back(it.first);
                    count++;
                    if(count ==2){
                        break;
                    }
                }
                if(it.second ==1){
                  nums.push_back(it.first);          
                }
            }
        }
        return nums.size();
    }
};

/*// erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3)*/

// This solution using map is my intuition array but nut modified on original array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize the counter and the array index.
        int i = 1, count = 1, length = nums.size();
        
        // Start from the second element of the array and process
        // elements one by one.
        //
        while (i < nums.size()) {
            
            // If the current element is a duplicate, 
            // increment the count.
            if (nums[i] == nums[i - 1]) {
                count++;
                // If the count is more than 2, this is an unwanted duplicate element
                // and hence we remove it from the array.
                if (count > 2) {
                    /*
                    std::vector<T>::iterator it = vec.begin();
    std::advance(it, pos);
    vec.erase(it);*/
                    vector<int>:: iterator it = nums.begin() ;
                    advance(it,i);
                    nums.erase(it);
                     // Note that we have to decrement the array index value to keep it consistent with the size of the array.
                     i--;
                }
            } else {
                // Reset the count since we encountered a different element
                // than the previous one.
                count = 1;
            }   
            // Move on to the next element in the array
            i++;
        }
            
        return  nums.size();;
    }
};

/*// erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3)*/
