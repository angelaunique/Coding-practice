/* 103. Binary Tree Zigzag Level Order Traversal
Medium

2260

103

Add to List

Share
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  vect;  
        if (root == nullptr) return vect;      
        queue<TreeNode *> q; // q is a treenode type, thus need to push root
        q.push(root);
        bool flip = true;
        while(!q.empty())  // 1
		{
            int size = q.size();// for loop 不能直接放q.size(),结果会位移后面一位
			vector<int> v;
            //cout << "q.size()" << q.size() << endl;
			for(int i = 0; i < size; i++) { // inside of for loop, small v.size to control tree level 保证准确遍历，控制层次//
			 
				TreeNode *cur = q.front();
				q.pop(); // change size here!!
				v.push_back(cur -> val); // 
				if(cur -> left)  q.push(cur -> left);
				if(cur -> right)   q.push(cur -> right);
            }
                // reverse after for loop, one for loop is one level
                if(!flip){
                    reverse(v.begin(), v.end());
			}
            flip = !flip;
			vect.push_back(v);
		}
		return vect;       
    }
};

//method 2 recursion
class Solution {
public:
vector<vector<int>> zigzagLevelOrder (TreeNode* root) {
    int h = height(root);
    vector<vector<int> > v(h);
    helper(root,v,0);
    for( int i = 1; i < v.size(); i += 2){
        reverse(v[i].begin(),v[i].end());
    }
        
    return v;
 }
    int height(TreeNode* root){
    if(root){
        return 1 + max(height(root->left),height(root->right));
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
// method3 same recursion

class Solution {
public:

    vector<vector<int>> vect;
    vector<vector<int>> zigzagLevelOrder (TreeNode* root) {
        DFS_levelorder(root,0);  //calling function to traverse whole tree by passing root and level order
        for( int i = 1; i < vect.size(); i += 2){
        reverse(vect[i].begin(),vect[i].end());
        } 
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

