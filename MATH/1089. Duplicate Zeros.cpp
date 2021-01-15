
/*
Friends Of Appropriate Ages
Find Lucky Integer in an Array
Leftmost Column with at Least a One
Given a fixed length array arr of integers, duplicate each occurrence of zero, 
shifting the remaining elements to the right.
Note that elements beyond the length of the original array are not written.
Do the above modifications to the input array in place, do not return anything from your function.

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res(arr.size());
        res=arr;// res copies original array
        int i=0, j=0;
        while(i<res.size() && j<arr.size()){// two pointers updated on top of arr
            if(res[i]==0 && j+1<arr.size()){
                arr[j]=0;
                arr[j+1]=0;
                i++;
                j+=2;
            } else{
                arr[j]=res[i];
                i++;
                j++;
            }
        }
        
    }
};
    
class Solution {
public:
    void duplicateZeros(vector<int>& v) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                v.insert(v.begin()+i,0);
                i+=1;// skip the 0 to go forward
                //for 1st 0, before erase {1, 0, 0, 2, 3, 0, 4, 5, 0},after erase{1, 0, 0, 2, 3, 0, 4, 5}
                v.erase(v.begin()+v.size()-1);//erase the last element to keep the size unchange
                /*Note that elements beyond the length of the original array are not written.*/
            }
        }
        return;
    }
};    