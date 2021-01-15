/*100. Same Tree
Easy

2492

70

Add to List

Share
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
*/
 //不是镜像树，是相同树！！
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
// recursion
/*
Approach 1: Recursion
Intuition

The simplest strategy here is to use recursion. Check if p and q nodes are not None, and their values are equal. If all checks are OK, do the same for the child nodes recursively.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         // p and q are both null
        if(!p && !q) return true;
       // one of p and q is null
        if(!p || !q) return false;
        /* spagati code
        if(p->val == q->val) 
        { return true;}
        else
            return false;*/
        if(p->val!= q->val)  return false;
        return  isSameTree( p->right, q->right) && isSameTree(p->left, q->left);
        // 关键点，这两部分得同时成立！！！ 才能解决 [1,2] [1,null,2] 这种特殊情况
        //而且必须right,right; left,left 因为不是镜像树，是相同树！！
        }
    
};
//iteration
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});
        
        while (!s.empty()){
            pair<TreeNode*, TreeNode*> curr = s.top();
            s.pop();
            
            if ((curr.first == NULL && curr.second != NULL) || (curr.first != NULL && curr.second == NULL))
                return false;
            else if (curr.first == NULL && curr.second == NULL)
                continue;
            else if (curr.first->val != curr.second->val)
                return false;
            else {//if everything else is true
                s.push({curr.first->right, curr.second->right});
                s.push({curr.first->left, curr.second->left});
            }            
        }
        
        return true;// if coninue until here, it means we arrive here, truel
    }
};
// java iteration
class Solution {
  public boolean check(TreeNode p, TreeNode q) {
    // p and q are null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return true;
  }

  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) return true;
    if (!check(p, q)) return false;

    // init deques
    ArrayDeque<TreeNode> deqP = new ArrayDeque<TreeNode>();
    ArrayDeque<TreeNode> deqQ = new ArrayDeque<TreeNode>();
    deqP.addLast(p);
    deqQ.addLast(q);

    while (!deqP.isEmpty()) {
      p = deqP.removeFirst();
      q = deqQ.removeFirst();

      if (!check(p, q)) return false;
      if (p != null) {
        // in Java nulls are not allowed in Deque
        if (!check(p.left, q.left)) return false;
        if (p.left != null) {
          deqP.addLast(p.left);
          deqQ.addLast(q.left);
        }
        if (!check(p.right, q.right)) return false;
        if (p.right != null) {
          deqP.addLast(p.right);
          deqQ.addLast(q.right);
        }
      }
    }
    return true;
  }
}
