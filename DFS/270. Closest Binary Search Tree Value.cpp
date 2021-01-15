/*
Count Complete Tree Nodes
Closest Binary Search Tree Value II

270. Closest Binary Search Tree Value
Easy

826

64

Add to List

Share
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// ceil(x) 31.1=32
//floor(x) 32.2=31
/*

class Solution {
private:
    void closestValue(TreeNode* root, double& distance, int& res, const double& target) {
        if (!root) return;
		 // If the distance we have is less than the current distance, this node is closer to our target
		 // than the previous node
        if (distance > abs(((double)root->val) - target)) {
            distance = abs(((double)root->val) - target); // Reset the distance
            res = root->val; // Save the value of the root in res
        }
        closestValue(root->left, distance, res, target);
        closestValue(root->right, distance, res, target);
        return;
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        double distance{numeric_limits<double>::max()}; // The worst distance possible
        int ourRes{}; // Store our result here.
        closestValue(root, distance, ourRes, target);
        return ourRes; // Return our result
    }
};
//This one does't work, need to combine with the upper sol to make it work
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = INT_MAX;
        if(!root) return 0;
        double t = (double) (root->val);
        if( root-> val == target) return root->val;
        
        if(res==INT_MAX || abs(res-target)> abs(t-target)) 
             res = t;
        if(t >target)  closestValue( root ->left,  target);
        else closestValue( root ->right,  target);
        //return 0; // if not found at the end
    }
};*/


/*
method1 iterative  
class Solution {
  public int closestValue(TreeNode root, double target) {
    int val, closest = root.val;
    while (root != null) {
      val = root.val;
      closest = abs(val - target) < abs(closest - target) ? val : closest;
      root =  target < root->val ? root.left : root->right;
    }
    return closest;
  }
}*/
/* 
method2: DFS recursive
class Solution {
public:
    int closest;
    
    int closestValue(TreeNode* root, double target) {
        closest = root->val;
        
        dfs(root, target);
        
        return closest;
    }
    
    
    void dfs(TreeNode* root, double target) {
        if (root == NULL)
            return;
        
        if (abs(root->val - target) < abs(closest - target) )// KEY!! compare with root, decidee to get left or root value as needed 
            closest = root->val;
        
        if (root->val < target) {
            dfs(root->right, target);
        } else if (root->val > target){
            dfs(root->left, target);
        } else {
            closest = (double) target;
        }
    }
};
*/
// method3 dfs recursive, binary search
// assumption: root != NULL
class Solution {
    public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        if (target < root->val && root->left) {
            int tl = closestValue(root->left, target);
            if (abs(target - tl) < (closest - target)) closest = tl;
        } else if (target > root->val && root->right) {
            int tr = closestValue(root->right, target);
            if (abs(target - tr) < (target - closest)) closest = tr;
        }
        return closest;
    }
};