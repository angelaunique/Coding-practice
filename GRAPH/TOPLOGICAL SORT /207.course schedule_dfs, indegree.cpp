/*207. Course Schedule

Share
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5*/



/*only case fail: cycle. If no cycles,Directed Acyclic Graph, use DFS to check dependencies( neighbors) we incrementally follow the dependencies until either there is no more dependency or we come across a previously visited course along the path.
 adjacency list data,
 Step 1). we build a graph data structure from the given list of course dependencies. Here we adopt the adjacency list data structure as shown below to represent the graph, which can be implemented via hashmap or dictionary. Each entry in the adjacency list represents a node which consists of a node index and a list of neighbors nodes that follow from the node.
 Step 2). we then enumerate each node (course) in the constructed graph, to check if we could form a dependency cycle starting from the node.

*/

class Solution {
public:    
   
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        // way to build adjacent list
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);// build adjacent list
        
        //  states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i)) // if there is a visited node third time, then detect a cycle, return false
                return false;
        }
        return true;
    }
    
      bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1) return true;//1 == visiting again
        if(vis[id]==2) return false;  //2 = visited 
        
        
        // otherwise, state unknow==0, we start visiting vis[id]=1;
        if(vis[id]==0){ //0 = unkonwn
            vis[id]=1;// visiting 
            for(auto edge : adj[id]){ // visit each id's neighbors 
                if(iscycle(adj,vis,edge)) // if visited ==1, then true , then visit next edge
                    return true;
            }
        }
        vis[id] = 2; // if vis[id]== 0, visiting, set to 1, 
        return false; 
    }
/*   
i: 0
n: 8
pre: {{1, 0}, {2, 6}, {1, 7}, {6, 4}, {7, 0}, {0, 5}}
vis: {0, 0, 0, 0, 0, 0, 0, 0}
__vla_expr0: 8
adj: {{1, 7}, , , , {6}, {0}, {2}, {1}}
*/

};
/*
8
[[1, 0], [2, 6], [1, 7], [6, 4], [7, 0], [0, 5]]
enter func iscycle:
             v(1)  0 v(2)=> false, go back to func canfinish ,continue for loop; the for loop will break  if(iscycle(adj,vis,edge)) return ture(a node will be reached a second time through
             
             another node, note through dfs), then canfinish will return false,done!
            / /      \\
 1:v(1)  {1,           7} 7: v(2)
        // 1:v(2) 7:v(1) \\
          null            {1}
                         false  
                         
                         
8
[[1, 0], [2, 6], [1, 7],[5,1], [6, 4], [7, 0], [0, 5]]       

           v(1)  0 
            /     
 1:v(1)  {1,  7}       
        /
5:v(1) 5
      /
    0 ,already v(1), thus return ture, if(iscycle(adj,vis,i)) , funct canFinish return false, means found cycle, done!
                                                 
*/

// method 2 toplogical sort solution [[1, 0], [2, 6], [1, 7],[5,1], [6, 4], [7, 0], [0, 5]]       
    int V=numCourses;
    if(V==0) return true;
    vector<int> adj[V];// adj: {, , , , , , , } == neighbours
    queue<int> q;
    vector<int> indegree(V,0);//indegree: {0, 0, 0, 0, 0, 0, 0, 0}  == number of coming neighbors
    int cnt=0;
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);//[0][1]=0, adj[0] = 1,adj[6] = 2,adj[0]=7
        indegree[prerequisites[i][0]]++;//indegree[1] = 2
    }// indegree {1, 2, 1, 0, 0, 1, 1, 1} indegree for [1] = 2 means 1 have two incoming neighbors
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);// if if(indegree[i]==0)  means it's a start visiting point
    }
    //adj: {{1, 7}, {5}, , , {6}, {0}, {2}, {1}}
    while(!q.empty()){
        int parent=q.front(); q.pop(); // parent is the node where degree ==0
        for(auto child : adj[parent]){//visit all child nodes connected to the 0 degree parents
            --indegree[child];// after VISITED(put into parent) ONE parent, the indegree of it's child got removed one
            if(indegree[child]==0) q.push(child);// if a child indgree ==0, means the that child can be put into the parent arr
        }
        cnt++;// count the number of elems in parent
    }
    
    
    return cnt==V;
    /*if parent.size() == # of vertex, then we visited all node without repeated, otherwise arent.size()  will < V， 
    since  cycle nodes won't be visited bc their indegree !=0, return false */
}