/*similar questions
Closest Binary Search Tree Value
Insert into a Binary Search Tree*/
/*700. Search in a Binary Search Tree
Easy

996

121

Add to List

Share
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // must generalize the name of the answer so it can return the same thing 
        if(!root) return NULL;
        if(root->val == val) return root;
        
        //if(root->left && val < root->left->val)  { // Binary Search tree must have < condition!, don't need to check null here, the first line covered this condition
           if (root->val > val) {
           return searchBST(root->left,  val) ; // directly return, don't need to name the returned node
            //if (tLeft) return tLeft; ---even null, also covered in the first line
           } else {
            return searchBST(root->right,  val) ;
            }
        return NULL; // Don't forget last condition, if not found, return null!
    }
    
};
/* method1 recusion
class Solution {
public:
    TreeNode* ans;
    TreeNode* searchBST(TreeNode* root, int val) 
    {   
        if(root==NULL) return NULL;
        if(root->val==val)
        {
            ans = root;
            return ans;
        }
        if(searchBST(root->left, val)!=NULL) return ans;
        if(searchBST(root->right, val)!=NULL) return ans;
        return NULL;
    }
};*/

/*method2
// recursive 60 ms 29.2MB
TreeNode* searchBST(TreeNode* root, int val) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->val == val) {
		return root;
	} else if (root->val > val) {
		return searchBST(root->left, val);
	} else {
		return searchBST(root->right, val);
	}
    
    // method3 iterative 48 ms	29.1 MB
TreeNode* searchBST(TreeNode* root, int val) {
	auto node = root;
	while (node != nullptr) {
		if (node->val == val) {
			return node;
		} else if (node->val > val) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	return node;
}
// method4 simple solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val) return root;
        return root->val > val? searchBST(root->left,val):searchBST(root->right,val);
        
    }
};
}*/