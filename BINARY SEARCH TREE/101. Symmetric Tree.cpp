/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

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
// method1 iterative way
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if(!root)  return true;
       queue<TreeNode*> q;
       q.push(root), q.push(root);// isolate root!!, just push rootleft and root right to check mirror   

       while(!q.empty()){                                       // 
           TreeNode *cur1 = q.front();//left 2                  // cur1= 3; 3,3,4,4 
		   q.pop(); //right 2                                   // 3,4,4
           TreeNode *cur2 =  q.front();//right 2                 //cur2 = 3    
           q.pop();//empty                                      // 4,4
           if(cur1 -> val != cur2 -> val) {//NOT cur1 -> left -> val != cur2 -> right ->val, NEED to check cur val first!
               return false; //3==3
           }
           // IMPOART! change push order!!!
		    if(cur1->left && cur2->right) { // if 5 and 5
            q.push(cur1->left); //4,4,5
            q.push(cur2->right); //4,4,5,5
            }  
             else if(cur1->left || cur2->right) return false; // if left is null right !=null false,vice verse
           // Same situation with l->right, r->left
            if(cur1->right && cur2->left) { // if 6 and 6
            q.push(cur1->right);//4,4,5,5,6 ptr
            q.push(cur2->left); //4,4,5,5,6,8 //ptr
         }
           else if(cur1->right || cur2->left) return false;
       }
       return true;
    }
};

// method1 recursive way
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if(!root)   return true;  // before pass in l and r, need to make sure the passed values are not junk( null)
                                     // thus better simplify as the case of ( root,root) , because if(!root) already cover the abnormal cas
       return checkSymmetric(root, root) ; //[1,null,2]
    }
    
    bool checkSymmetric(TreeNode * cur1, TreeNode * cur2) { 
        if(!cur1 && !cur1) return true;
        if( (cur1 && cur2) && (cur1 -> val == cur2-> val) && checkSymmetric(cur1 -> left, cur2 ->right ) && checkSymmetric(cur1 -> right, cur2 -> left))             return true;
        return false;
    }
};
// note case1, make sure root left,right not now
// ture 情况归类： 1.两个都是 null. 2, 满足true 的所有条件:  (cur1 && cur2), (cur1 -> val == cur2-> val),checkSymmetric(cur1 -> left, cur2 ->right //),checkSymmetric(cur1 -> right, cur2 -> left)
//其他全为false