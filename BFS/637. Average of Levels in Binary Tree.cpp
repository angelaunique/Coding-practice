/* Similar questions
Binary Tree Postorder Traversal
Search in a Binary Search Tree
Find a Corresponding Node of a Binary Tree in a Clone of That Tree
*/
/*637. Average of Levels in Binary Tree
Easy

1423

169

Add to List

Share
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            int sz= q.size();
            double dsum = 0.0; // 0.0 not 0!     
             for(int i = 0; i < sz; i++){
                auto t = q.front();
                q.pop(); // don't forget to opo!
                dsum += t->val; 
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
              }  
            double avg = dsum/sz; 
            res.push_back(avg);     
        }
        return res;  
    }
};