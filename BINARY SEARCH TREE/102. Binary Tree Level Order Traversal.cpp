
/*102
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
//BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 1. if the tree root is null -> empty []
        //2 first treenode into array, then traverse to the 1st level, left+ right into an array,if null, ignore */
        
        vector<vector<int>>  vect;  
        if (root == nullptr) return vect;      
        queue<TreeNode *> q; // q is a treenode type, thus need to push root
        q.push(root);
     
        while(!q.empty())  // 1
		{
            int size = q.size();// for loop 不能直接放q.size(),结果会位移后面一位
			vector<int> v;
            //cout << "q.size()" << q.size() << endl;
			for(int i = 0; i < size; i++) // vector size to control tree level 保证准确遍历，控制层次//
			{ 
				TreeNode *cur = q.front();
				q.pop(); // change size here!!
				v.push_back(cur -> val); // 
				if(cur -> left)  q.push(cur -> left);
				if(cur -> right)   q.push(cur -> right);
			}
			vect.push_back(v);
		}
		return vect;       
    }
};

/*
q.size()1
q.size()2
q.size()1
q.size()2
q.size()1*/
/*
size()1
size()2
size()2
size()2
size()2*/

// DFS method 2 USE vect size as level control!!!
class Solution {
public:

    vector<vector<int>> vect;
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS_levelorder(root,0);  //calling function to traverse whole tree by passing root and level order
        return vect;  
    } 
    
    void DFS_levelorder(TreeNode* root,int level) 
    {
        if(!root) return;  //if root is NULL then return
        if(level==vect.size())  //if level is equal to answer size then we have to push one empty element into it
            vect.push_back(vector<int> ());  //push a new empty vector into vect // CAN'T Directly put an empty vec inside
        vect[level].push_back(root->val);  //pushing current node to the level index of answer
        DFS_levelorder(root->left,level+1);  //recursive call to traverse left subtree by increasing the level order
        DFS_levelorder(root->right,level+1);  //recursive call to traverse right subtree by increasing the level order
    }  
};
/*102
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
/*
level :0
vect: 1
level :1
vect: 2
level :1
vect: 2
level :2
vect: 3
level :2
vect: 3 */

/* method3*/
public:
int h;
vector<vector<int>> levelOrder(TreeNode* root) {
    h=height(root);
    vector<vector<int> > v(h);
    helper(root,v,0);
    return v;
    }
int height(TreeNode* root){
    if(root){
        return 1+max(height(root->left),height(root->right));
    }
    return 0;
}
void helper(TreeNode* root,vector<vector<int> >&v,int c_level){
      if(root){
        v[c_level].push_back(root->val);
        helper(root->left,v,c_level+1);
        helper(root->right,v,c_level+1);
        }
    return;
    }
};


