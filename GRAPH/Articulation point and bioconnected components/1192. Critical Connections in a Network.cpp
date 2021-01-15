/* Concept:https://www.hackerearth.com/practice/notes/nj/
Smiliar problems:
Recover Binary Search Tree
Populating Next Right Pointers in Each Node
Nested List Weight Sum II
1192. Critical Connections in a Network
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 
Constraints:
1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/
Best video
//https://www.youtube.com/watch?v=mKUsbABiwBI

/*here are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/
class Solution(object):
    
    def criticalConnections(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
        g = collections.defaultdict(set)
        for u,v in connections: #construct graph
            g[u].add(v)
            g[v].add(u)
        jump = [-1] * n #depth for level 
    """
    string from the current node, explore all the node conncecting to this node except for its parent,
    and return the minum value node
    
    """
        def dfs(v, par, lvl, jump,res,g): 
            jump[v] = lvl +1 # every time move forward with dfs search, level+1 
            //jump=alternative path to jump back to root parent: the lowest steps to root that the child has seen so far, can be samller that it's parent's levl

            for child in g[v]://从0开始，把所有的child 拿出来开始探索。
            //返回的时候，如果见到另外一个path可以返回到根节点，意味着我们都在一个环里面，我们都不是critical path
                if child == par://因为是双向的，如果其中一个child 是parent,就知道是重复访问了。如果已经访问过，跳过
                    continue
                elif jump[child] == -1: # if not visited, dfs search to visit, 如果没访问过的，就开始访问
                    jump[v] = min(jump[v],dfs(child,v,lvl+1, jump,res,g)) //访问的时候，此时当前的child 就变parent,当前节点就变child； 其他不变
                    //jump[v]我见过的最小jump = 我的孩子见过的最小节点，不断刷新下限
                else:           
                    jump[v] = min(jump[v], jump[child])//如果已经访问过，就取我和孩子的最小节点。比如访问root的孩子的时候，这时候root就是孩子的孩子，那么root已经访问过了，就选择两者之中最小的jump 回去就行
            if jump[v] == lvl +1 and v!= 0:     #if jump[v] == lvl +1 //is not updated,means it doesn't have another path to connect to grandparents, IT IS A CRITICAL CONNECTION
                                                         # at the end of the big function criticalConnections返回的时候如果lvl没有被修改，就是critical connection
                res.append([par,v]) # append tuple
            return jump[v]
        # v = 0(-1) is the dummy edge, skip it, 
       
        res = []
        dfs(0,-1,0,jump,res,g)
        return res                            
/*                                      
       #when move forward, in dfs, current child become parent, next current node v become child, jump updated with  for child in g[v]:, res updated at the end, g stays the same
            #:# if already visited,just take the min bw itself and it's child
                #at the same time to update the jump level depth to min, since if there is a circle, then jump[v] will be updated to lower number since the node might 
                see it's parent's parent, 
                thus, the child can go to grandparent without going through parent, means circle exist, not a critical path        

 // better c++ version    
 //没用环，因为太多环 很难都找到                
  //核心思想，取掉一条边，看能不能tranverse到所有到顶点 。找环，一个环上的任何一条边都不可能是critical connection，用dfs可以找到所有的环
  //DFS向前探索，每个节点最多走一遍，每走一步记录从从原点走到当前节点的步数
  //DFS探索完返回：返回当前节点所间接接触到的最小步数的节点                               
     class Solution {
public:
    vector<vector<int>> res;
    vector<int>entry_time；
    vector<int> lowest_entry_time;
    int tem = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
         entry_time.resize(n, -1);
        lowest_entry_time.resize(n, -1);
        
        
        //creation of adjacency list
        vector<vector<int>>adj(n);
        for(int i = 0; i < connections.size(); ++i){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        //vector to mark visited
        vector<bool>vis(n, false);
        //function for finding critical connections
        findCC(adj, vis);
        
        return res;
    }
    
    void findCC(vector<vector<int>>&adj, vector<bool>&vis){
        int n = adj.size();
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
    }
    
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int node, int par = -1){
        vis[node] = true;
        lowest_entry_time[node] = entry_time[node] = tem++; //when node is first visited 
        
        for(int nei : adj[node]){
            if(nei == par)continue;
            
            //edge with already visited node means the edge is a back edge
            if(vis[nei]){
                lowest_entry_time[node] = min(lowest_entry_time[node], entry_time[nei]);
            }
            else{
                //fill lowest entry time of children in dfs tree
                dfs(adj, vis, nei, node);
                
                //update lowest entry time of node 
                lowest_entry_time[node] = min(lowest_entry_time[node], lowest_entry_time[nei]);
                
                //condition for an edge to be a critical connection
                if(lowest_entry_time[nei] > entry_time[node]){
                    res.push_back(vector<int>{node, nei});
                }
            }
        }
    }
};           
        

// method 2 DFS
*/
#define INF 0x3f3f3f3f
class Solution {
public:
    
    vector < vector <int> > adj, bridges;
    vector <bool> visited; 
    
    vector <int> disc, low;
    
    void dfs(int u, int parent)
    {
        static int tim = 1;
        disc[u] = low[u] = tim++;
        int child = 0;
        visited[u] = true;
        
        for(auto ele: adj[u])
        {
            if(!visited[ele])
            {
                child++;
                dfs(ele, u);
                low[u] = min(low[u], low[ele]);
                if(low[ele] > disc[u])
                {
                    vector <int> temp;
                    temp.push_back(u);
                    temp.push_back(ele);
                    bridges.push_back(temp);
                }
            }
            else if (ele != parent)
            {
                low[u] = min(low[u], disc[ele]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
                
        visited.resize(n, false);
        disc.resize(n, INF);
        low.resize(n, INF);
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
                
        return bridges;
    }
};
                  
  