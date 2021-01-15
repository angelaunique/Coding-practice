
/*Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

 
Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.

// C++ program to demonstrate default behaviour of 
// sort() in STL. 
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sort(arr, arr+n); 
  
    cout << "\nArray after sorting using "
         "default sort is : \n"; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
  
    return 0; 
} 
 */
 class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int numGoodTriplets = 0;
        for (int i = 0; i < arr.size() - 2; i++)
            for (int j = i + 1; j < arr.size() - 1; j++)
                for (int k = j + 1; k < arr.size(); k++)
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                        numGoodTriplets++;
        return numGoodTriplets;
    }
};