
// REMEMBER input is an array.
// BFS, QUEUE, main body TWO LOOPS!(1) while !q.empty (2) while (size --) , no RECURSION!!!!!

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
class Solution {// this method has overflow
public:
    
    int widthOfBinaryTree(TreeNode* root) {
       if( root == NULL ) return 0;
       if( root && (root-> left == NULL) && (root-> right == NULL) ) return 1;
        
        //queue<int> q;// need to create queque pair to hold node and col_index
        queue<pair<TreeNode*, int > > q;// queue<pair<TreeNode*, int> > q;, first parameter is type TreeNode*!
        int w = 0;
        
        //q.push(pair<TreeNode*, unsigned  long long>(root, 1));
        
        // syntax for push queue pairs : q.push({ root -> val})
        q.push({root,0}); //append the root node along with its index 0, to kick off the BFS traversal.
       /* The BFS traversal is basically an iteration over the elements of queue. We visit the nodes level by level until there are no more elements in the queue.*/
        
        while( !q.empty()){
            auto node = q.front().first;
            auto idx = q.front().second;
            
            // iterate through the current level;
            
            int size = q.size();
            while(size --){
                q.pop();
                if( node->left )
                    q.push({node->left, idx*2});
                if( node->right )
                    q.push({node->right, idx*2+1});           
            }   
            w = max(q.back().second - q.front().second + 1, w);      
         }
        return w;
        /*At the end of BFS traversal, we then return the maximal width that we've seen over all levels.*/
    }
    
};
// to fix overflow
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long maxe = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(pair<TreeNode*, unsigned  long long>(root, 1));
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l; // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, unsigned long long>(node->left, r * 2));
                if (node->right) q.push(pair<TreeNode*, unsigned  long long>(node->right, r * 2 + 1));
            }
            maxe = max({maxe, r + 1 - l});
        }
        return (int)maxe;
    }
};;


//The key to solve the problem though lie on how we index the nodes that are on the same level.
// has nothing to do node's value!!!!
/*
If the index of a parent node is C_iC 
i
​	
 , accordingly we can define the index of its left child node as 2\cdot C_i2⋅C 
i
​	
  and the index of its right child node as 2 \cdot C_i + 12⋅C 
i
​	
 +1.*/

class Solution {
    // to avoid overflow, change node value to index number!
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)  return 0;
        int w = 0;
        queue<TreeNode*> q;
        root->val = 0;// set root index = 0;
        
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            int minIndex;
            for (int i = 0; i < s; i++) {
                
                TreeNode* t = q.front();
                q.pop();
                
                // two cases to handle overflow
                if (i == 0) minIndex = t->val;// if i = 0, index = 0
                if (i == s - 1) w = max(w, t->val - minIndex + 1);// if i = size -1, index = max( , curIndex - minInex +1)
               
                t->val = t->val - minIndex;
                
                if (t->left) {
                    t->left->val = 2 * t->val;
                    q.push(t->left);
                }
                if (t->right) {
                    t->right->val = 2 * t->val + 1;
                    q.push(t->right);
                }
            }
        }
        return w;
    }
};


/*DFS
It might sound twisted, but we don't need to visit the nodes strictly in the order of BFS. All we need is to compare the indices between the first and the last elements of the same level.

Better yet, we don't need to keep the indices of the entire level, but the first and the last index.
 we use a table with depth of the node as the key and the index of the first element for that depth (level) as the value.
If we can make sure that we visit the first element of a level before the rest of elements on that level, we then can easily populate the table along with the traversal.
Although in principle DFS prioritizes depth over breadth, it could also ensure the level-wise priority. By visiting the left node before the right child node in DFS traversal, we can ensure that the nodes that lean more to the left got visited earlier.
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
      if(root == nullptr) return 0;
      dfs(root, 0, 0); //position of this node and the current depth
      return maxWidth;
    }
  
private:
  int maxWidth = INT_MIN;
  unordered_map<int, unsigned long int> leftPosition; //[depth] : [leftmostnode Position]
  void dfs(TreeNode* root, unsigned long int position, int depth){
    if(root == nullptr) return;
    
    //Only if a leftModeNode position is not already present at this depth
    if(leftPosition.count(depth) == 0){//if position not present
      leftPosition[depth] = position;// add position
    } 
    
    int leftMostposition = leftPosition[depth];
    /*Calculate the max width*/
    int widthAtCurrentDepth = position - leftMostposition + 1;
    maxWidth = max(maxWidth, widthAtCurrentDepth);
    
    dfs(root->left, position*2, depth+1);
    dfs(root->right, position*2 + 1, depth+1);
  }
};
// java DFS with hashmap to retrive the first index,  KEY POINTS is that we can polulate to right with formula 2 * colIndex + 1)
class Solution {
    private Integer maxWidth = 0;
    private HashMap<Integer, Integer> firstColIndexTable;

    protected void DFS(TreeNode node, Integer depth, Integer colIndex) {
        if (node == null)
            return;
        // initialize the value, for the first seen colIndex per level
        if (!firstColIndexTable.containsKey(depth)) {
            firstColIndexTable.put(depth, colIndex);
        }
        Integer firstColIndex = firstColIndexTable.get(depth);

        maxWidth = Math.max(this.maxWidth, colIndex - firstColIndex + 1);

        // Preorder DFS. Note: it is important to put the priority on the left child
        DFS(node.left, depth + 1, 2 * colIndex);// This is just for fill in the first index
        DFS(node.right, depth + 1, 2 * colIndex + 1);//KEY POINTS is that we can polulate to right with formula 2 * colIndex + 1)
    }

    public int widthOfBinaryTree(TreeNode root) {
        // table contains the first col_index for each level
        this.firstColIndexTable = new HashMap<Integer, Integer>();

        // start from depth = 0, and colIndex = 0
        DFS(root, 0, 0);

        return this.maxWidth;
    }
}