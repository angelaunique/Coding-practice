/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int,int> u;
            for(int i=0;i<inorder.size();i++)
            {
                u[inorder[i]]=i;
            }
            return helper(inorder,postorder,0,inorder.size()-1,postorder.size()-1,u);
    }
    TreeNode* helper(vector<int> &inorder,vector<int> &postorder,int inStart, int inEnd, int postIndex,unordered_map<int,int> &u)
    {
        if(inStart>inEnd || postIndex<0)
            return NULL;
        TreeNode* root=new TreeNode(postorder[postIndex]);
        int index=-1;
        if(u.find(postorder[postIndex])!=u.end())
            index=u[postorder[postIndex]];
        
        root->right=helper(inorder,postorder,index+1,inEnd,postIndex-1,u);
        root->left=helper(inorder,postorder,inStart,index-1,postIndex-(inEnd-index+1),u);
        return root;      
    }
};