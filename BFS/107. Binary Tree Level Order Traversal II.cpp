/*107. Binary Tree Level Order Traversal II
Easy

1645

220

Add to List

Share
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>>  res;
       queue<TreeNode*> q;
      // stack<vector<int>> s;
       if(!root ) return vector<vector<int>>{};
       
       q.push(root);// only the first one is root->val
       while(!q.empty()){
          int sz = q.size(); //Don't forget this step! 
          vector<int> v; 
          for(int i=0; i<sz; i++) {  
              auto tNode = q.front();// int temp = q.pop() does't work!// since treenode inq, thus must use auto
              q.pop(); 
              v.push_back(tNode->val);   
              if(tNode->left) q.push(tNode->left); // root kept changing,thus need to push node to q and use popped q(node) to keep track of left and right ,can't q.push(root->left->val); !!! not push in val, but treeNode
              if(tNode->right) q.push(tNode->right);        
          }
           res.push_back(v);
       } 
       
        return vector<vector<int>>(res.rbegin(),res.rend());  // To simply reverse the vector  
    }
};

