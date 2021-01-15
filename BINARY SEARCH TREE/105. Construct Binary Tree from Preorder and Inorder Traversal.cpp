/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

[3,9,20,null,null,15,7] */

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

// IMPORTANT CONCEPT: DEFINE THE NUMBER OF PARAMETERS FOR RECURSIVE FUNCTIONS
// method1 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map <int, int> map;  // for getting index in inorder   preorder = [3,[9,20],[15,7]] 
       for ( int i = 0; i < inorder.size(); i++) {
              map[inorder[i]] = i; // inorder [[9,] 3, [15,[20,] 7]]
       } 
      return helper(preorder, inorder,0,0, inorder.size() -1, map) ; 
  }
   
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int preStart, int inStart, int inEnd, unordered_map <int, int> &map){   
	    if(preStart >= preorder.size() || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);// create root node
        
        int rootIndex = map[preorder[preStart]]; //get root index;
        root->left = helper(preorder, inorder, preStart + 1,  inStart, rootIndex -1 , map);
        root->right = helper(preorder, inorder, preStart + rootIndex - inStart +1,  rootIndex +1, inEnd,  map);
        return root;
    }
};

// method2 index = preStart, it's the root

class Solution {

    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        unordered_map<int, int> dict;
        
        // Store all the inorder indices to get start and end for each node's left and right nodes
        for (int i = 0; i < inorder.size(); ++i) 
            dict[inorder[i]] = i;      
        return helper(preorder, inorder, 0, preorder.size() - 1, index, dict);
    }
    private:
    // start and end variables indicate the start of the inorder index and the end of the inorder index respectively. 
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index, unordered_map<int, int> &dict) {
        if (start > end) return NULL;
    
        TreeNode *node = new TreeNode(preorder[index]);
        int i = dict[preorder[index++]];
        node -> left = helper(preorder, inorder, start, i - 1, index, dict);
        node -> right = helper(preorder, inorder, i + 1, end, index, dict);
        return node;
    }
};