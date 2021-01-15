/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 */
 // Java solution
//sol 1 brute force
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}

//Approach 2: Using Cumulative Sum
/*bc k is a sum, create sum array
Instead of determining the sum of elements everytime for every new subarray considered, we can make use of a cumulative sum array , sumsum. . Then, in order to calculate the sum of elements lying between two indices, we can subtract the cumulative sum corresponding to the two indices to obtain the sum directly, instead of iterating over the subarray to obtain the sum.
In this implementation, we make use of a cumulative sum array, sumsum, such that sum[i]sum[i] is used to store the cumulative sum of numsnums array upto the element corresponding to the (i-1)^{th}(i−1) 
th
  index. Thus, to determine the sum of elements for the subarray nums[i:j]nums[i:j], we can directly use sum[j+1] - sum[i]sum[j+1]−sum[i].
*/
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <=nums.length; i++)//start with i=1 since there is i-1 below, also i can reach to nums.length, because we use i-1
            sum[i] = sum[i - 1] + nums[i - 1];
        // iterate through sum
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
}
/*Time complexity : O(n^2)O(n 
2
 ). Considering every possible subarray takes O(n^2)O(n 
2
 ) time. Finding out the sum of any subarray takes O(1)O(1) time after the initial processing of O(n)O(n) for creating the cumulative sum array.

Space complexity : O(n)O(n). Cumulative sum array sumsum of size n+1n+1 is used.*/
// Approach 3: Without Space
/*
Instead of considering all the startstart and endend points and then finding the sum for each subarray corresponding to those points, we can directly find the sum on the go while considering different endend points. i.e. We can choose a particular startstart point and while iterating over the endend points, we can add the element corresponding to the endend point to the sum formed till now. Whenver the sumsum equals the required kk value, we can update the countcount value. We do so while iterating over all the endend indices possible for every startstart index. Whenver, we update the startstart index, we need to reset the sumsum value to 0.*/
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
//Approach 4: Using Hashmap
/*
r, if the cumulative sum upto two indices, say ii and jj is at a difference of kk i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices ii and jj is k*/
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}