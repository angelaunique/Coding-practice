// Author: Huahua
https://www.youtube.com/watch?v=wmW8G8SrXDs&list=PLLuMmzMTgVK5Hy1qcWYZcd7wVQQ1v0AjX&index=3
/*
Prim’s Algorithm
Time complexity: O(ElogV)
Space complexity: O(V+E)
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main(int argc, char** argv) {
  const int n = 4;
  vector<vector<int>> edges{{0,1,1},{0,3,3},{0,2,6},{2,3,2},{1,2,4},{1,3,5}};
  vector<vector<pair<int, int>>> g(n);//graph of n edges 
  //for loop建图
  for (const auto& e : edges) {
    g[e[0]].emplace_back(e[1], e[2]);
    g[e[1]].emplace_back(e[0], e[2]);
  }
  /*Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args
   as the arguments for its constructor.*/

  priority_queue<pair<int, int>> q; // (-w, v)
  vector<int> seen(n);
  q.emplace(0, 0); // (-w, v)
 //以下计算munimum cost
  int cost = 0;
  for (int i = 0; i < n; ++i) {
    while (true) {//为了跳过在seen里的node又保持在当前的for loop iteration
      const int w = -q.top().first;//取出weight，变回正数
      const int v = q.top().second;
      q.pop();
      if (seen[v]++) continue;//如果这个顶点对面的边已经计算过了，跳过, directly go back to while loop, not For loop!
      cost += w;
      for (const auto& p : g[v]) {//循环检查p的邻居邻居 把所有邻居都加进去此题起始点为0，在graph 里检查领奖
        if (seen[p.first]) continue;//如果此顶点以及被链接过了（已经是邻居了），跳过
        q.emplace(-p.second, p.first);//q还不是p在graph 的邻居，把weight以及新对边顶点放入优先队列，weight要为负数
      }
      break;
    }
  }
  cout << cost << endl;
  return 0;
}

/*Kruskal’s Algorithm
Time complexity: O(ElogV)
Space complexity: O(V+E)*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
 
int main(int argc, char** argv) {
      const int n = 4;

      vector<vector<int>> edges{{0, 1, 1}, {0, 3, 3}, {0, 2, 6},
                                {2, 3, 2}, {1, 2, 4}, {1, 3, 5}};
      vector<vector<int>> q;  // (w, u, v)
    //for loop建图
      for (const auto& e : edges) 
          q.push_back({e[2], e[0], e[1]});//把e[2]放最前面已方便按照边weight排序
      sort(begin(q), end(q));

      vector<int> p(n);//parent 数组是自己个数
      iota(begin(p), end(p), 0);//初始化p 全部为0
      /*Store increasing sequence
iota (numbers,numbers+10,100);
numbers: 100 101 102 103 104 105 106 107 108 109

*/
    // 从下面的for loop先开始
      function<int(int)> find = [&](int x) {//类似 union find 里的function 
        return x == p[x] ? x : p[x] = find(p[p[x]]);// path compression
      };
// find minimum cost
      int cost = 0;
      for (const auto& t : q) {
        int w = t[0], u = t[1], v = t[2];
        int ru = find(u), rv = find(v);
        if (ru == rv) continue;//如果parent相同，说明u,v已经是连接起来的
        p[ru] = rv;  // merge (u, v)//否则未连接，合并连接u,v其中u为parent
        cost += w;
      }
      cout << cost << endl;

      return 0;
}
