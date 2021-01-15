
/*
79. Word Search
Medium

4058

195

Add to List

Share
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/


///深度搜索，重点是弄清楚base cases!!!
class Solution {
private:
    int n,m;
    
public:    
   

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        n = board.size();// row
        m = board[0].size();// col
        
        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++)
            {
                if(dfs(board,word,0,i, j)) // 如果搜索完所有 return true,说明找到了
                    return true;
            }
        }
        return false;
    }
    
     //vector<vector<bool>> vis; //board of visited
    bool dfs(vector<vector<char>> &board, string word,int d,int x, int y)
    {
        if(word.size() == d) //Signifies that we have reached the end of search
            return true;
        
        // combine base case1 and 2--if out of bound or not found, return false
        if( x<0 || x>=board.size() || y <0 || y>=board[0].size()|| word[d] != board[x][y]) 
            return false;
        //We check if element is within bounds and then check if the character at that is the same as the corresponding character in string word
        
        // if found!
        if (d == word.length()-1) return true;// THIS IS THE FINAL FOUND CASE
        
        char cur = board[x][y];//横着走
        board[x][y] = ' ';//递归之前标识为不能走''，格子中其他任何字母均无冲突；比重新创立一个board节省空间 //To show that we have visited this node
        //往四个方向搜索，任何一个方向找到了是true
        bool found =  dfs(board, word, d+1,x+1,y)
                    ||dfs(board, word, d+1,x-1,y)
                    ||dfs(board, word, d+1,x,y+1)
                    ||dfs(board, word, d+1,x,y-1);
        board[x][y] = cur; //如果能走找到了，复原格子中的值 //Restore the element after checking
        return found;
    }
};

