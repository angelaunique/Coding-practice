
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 /*Approach 1: BFS: Two Queues
Let's use two queues: one for the current level, and one for the next. The idea is to pop the nodes one by one from the current level and push their children into the next level queue. Each time the current queue is empty, we have the right side element in hands.
Algorithm

Initiate the list of the right side view rightside.

Initiate two queues: one for the current level, and one for the next. Add root into nextLevel queue.

While nextLevel queue is not empty:

Initiate the current level: currLevel = nextLevel, and empty the next level nextLevel.

While current level queue is not empty:

Pop out a node from the current level queue.

Add first left and then right child node into nextLevel queue.

Now currLevel is empty, and the node we have in hands is the last one, and makes a part of the right side view. Add it into rightside.

Return rightside.
*/
// python code
/*
Time complexity: \mathcal{O}(N)O(N) since one has to visit each node.

Space complexity: \mathcal{O}(D)O(D) to keep the queues, where DD is a tree diameter. Let's use the last level to estimate the queue size. This level could contain up to N/2N/2 tree nodes in the case of complete binary tree.*/
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        next_level = deque([root,])
        rightside = []
        
        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()

            while curr_level:
                node = curr_level.popleft()
                    
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            # The current level is finished.
            # Its last element is the rightmost one.
            rightside.append(node.val)
        
        return rightside

/*
Approach 2: BFS: One Queue + Sentinel
Another approach is to push all the nodes in one queue and to use a sentinel node to separate the levels. Typically, one could use null as a sentinel.

diff

The first step is to initiate the first level: root + null as a sentinel. Once it's done, continue to pop the nodes one by one from the left and push their children to the right. Stop each time the current node is null because it means we hit the end of the current level. Each stop is a time to update a right side view list and to push null in the queue to mark the end of the next level.
Algorithm

Initiate the list of the right side view rightside.

Initiate the queue by adding a root. Add null sentinel to mark the end of the first level.

Initiate the current node as root.

While queue is not empty:

Save the previous node prev = curr and pop the current node from the queue curr = queue.poll().

While the current node is not null:

Add first left and then right child node into the queue.

Update both previous and current nodes: prev = curr, curr = queue.poll().

Now the current node is null, i.e. we reached the end of the current level. Hence the previous node is the rightmost one and makes a part of the right side view. Add it into rightside.

If the queue is not empty, push the null node as a sentinel, to mark the end of the next level.
Return rightside.

*/

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        queue = deque([root, None,])
        rightside = []
        
        curr = root
        while queue:
            prev, curr = curr, queue.popleft()

            while curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                    
                prev, curr = curr, queue.popleft()
            
            # the current level is finished
            # and prev is its rightmost element      
            rightside.append(prev.val)
            # add a sentinel to mark the end 
            # of the next level
            if queue:
                queue.append(None)
        
        return rightside
/*  Complexity Analysis

Time complexity: \mathcal{O}(N)O(N) since one has to visit each node.

Space complexity: \mathcal{O}(D)O(D) to keep the queues, where DD is a tree diameter. Let's use the last level to estimate the queue size. This level could contain up to N/2N/2 tree nodes in the case of complete binary tree.
*/      


/*Approach 3: BFS: One Queue + Level Size Measurements
Instead of using the sentinel, we could write down the length of the current level.

Algorithm

Initiate the list of the right side view rightside.

Initiate the queue by adding a root.

While the queue is not empty:

Write down the length of the current level: levelLength = queue.size().

Iterate over i from 0 to level_length - 1:

Pop the current node from the queue: node = queue.poll().

If i == levelLength - 1, then it's the last node in the current level, push it to rightsize list.

Add first left and then right child node into the queue.

Return rightside.*/
// Key to solve this problem, size of queue = level_length of queue, for loop to go through len
// IMPORTANT queue <TreeNode* > q; q.push(node );q.front();q.pop();
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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightSide;// store result values, rightSide = len-1 of every level
        if( root == NULL) return rightSide;
        queue <TreeNode* > q;
        
        q.push(root);// enque ThreeNode *, not enque, use PUSH 
        while(! q.empty()){
            int level_length = q.size();
            
            // add rightmost element of each level
            for( int i = 0; i < level_length; i++){
               TreeNode* node = q.front();//not q.pop(), bc pop return void 
                q.pop();
               if ( i == level_length -1)  rightSide.push_back(node->val);
                
            // continue to construct BFS queue along the tree
               if( node->left ) q.push(node->left);
               if( node->right ) q.push(node->right);             
            }
        }
        return rightSide;
    }
};
/*
Complexity Analysis

Time complexity: \mathcal{O}(N)O(N) since one has to visit each node.

Space complexity: \mathcal{O}(D)O(D) to keep the queues, where DD is a tree diameter. Let's use the last level to estimate the queue size. This level could contain up to N/2N/2 tree nodes in the case of complete binary tree.
*/
// Approach 4: Recursive DFS
// The idea is simple: to traverse the tree level by level, starting each time from the rightmost child.
     class Solution {
    List<Integer> rightside = new ArrayList();
    
    public void helper(TreeNode node, int level) {
        if (level == rightside.size()) // use len of reslut vetor(rightside)as level!!! and append the 
            rightside.add(node.val);
        
        if (node.right != null) 
            helper(node.right, level + 1);  // helper function to inctease level
        if (node.left != null) 
            helper(node.left, level + 1);// both if function sequentionly run, same level since both are:level + 1!!!
    }    
    
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return rightside;
        
        helper(root, 0);
        return rightside;
    }
}
/*
Complexity Analysis

Time complexity: \mathcal{O}(N)O(N) since one has to visit each node.

Space complexity: \mathcal{O}(H)O(H) to keep the recursion stack, where HH is a tree height. The worst-case situation is a skewed tree, when H = NH=N.
*/


