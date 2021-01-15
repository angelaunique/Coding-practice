/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
/*cases return []
case1: numCourses = 0;
case2: detect cycle,it is not possible to have e.g. two subjects S1 and S2 prerequisites of each other
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> preqOrd;   
    vector<int> preqOrdempty;    
    int V=numCourses;
        
    if(V==0) return preqOrd;
        
        
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
        preqOrd.push_back (parent);
        for(auto child : adj[parent]){//visit all child nodes connected to the 0 degree parents
            --indegree[child];// after VISITED(put into parent) ONE parent, the indegree of it's child got removed one
            if(indegree[child]==0) q.push(child);// if a child indgree ==0, means the that child can be put into the parent arr
            }
        cnt++;// count the number of elems in parent
        }
        
        if(cnt != V ) return  preqOrdempty;
        
    return preqOrd;          
    }
};