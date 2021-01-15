/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0; //  if (grid.empty()) == is wrong!!
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;//初始化小岛数量为0
        //vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int y=0; y < m; y++) //枚举起点的任何位置
            for(int x=0; x <n; x++){
                //从任何一个位置开始，如果为0，进dfs之后就return; 如果为1，说明就找到了岛到其实位置，进入dfs,把找到到邻居全部转换为0，因此就不会重复计小岛数量，+到ans上到就是准确值
                //ans += grid[y][x] -'0';;// 如果原来是1，仍是1；如果0，就是0。本质复制格子上的字符到ans，- char‘0’ 得到数字
                if( grid[y][x] == '1'){
                    ++ans;
                dfs(grid, x,y,n,m); // 如果搜索完所有 return true,说明找到了
                }
            }
        return ans;
    }

private:    
    void dfs(vector<vector<char>> & board, int x, int y,int n, int m)
    {
        // if out_of_bound || sees an "0",return
        if( x< 0 || x >=n || y < 0 || y>=m || board[y][x] =='0')
            return ;
        board[y][x] = '0';//否则到了这一步遇到到肯定是1，走到标记为水//继续走，找到所有到1，全部变为0
        //往四个方向搜索，任何一个方向找到了是true
        dfs(board, x + 1, y,n,m);
        dfs(board, x - 1, y,n,m);
        dfs(board, x ,y + 1,n,m);
        dfs(board, x ,y - 1,n,m);
        // 不需要回溯，递归前更改了状态，不需要在递归后恢复过来，因为最后就是要把陆地沉下去
    }//最后返回把小岛全部沉到水里 
};


