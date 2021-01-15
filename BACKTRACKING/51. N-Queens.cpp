/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

/* method1: constrained programming. 
    That basically means to put restrictions after each queen placement. One puts a queen on the board and that immediately excludes one column, one row and two diagonals for the further queens placement. That propagates constraints and helps to reduce the number of combinations to consider.*/

/*
backtrack(row = 0).

Start from the first row = 0.

Iterate over the columns and try to put a queen in each column.

    If square (row, column) is not under attack

        Place the queen in (row, column) square.
        Exclude one row, one column and two diagonals from further consideration.
        If all rows are filled up row == N
        That means that we find out one more solution.
    Else
        Proceed to place further queens backtrack(row + 1).
    Now backtrack : remove the queen from (row, column) square.
*/

/*Time complexity : \mathcal{O}(N!)O(N!). There is N possibilities to put the first queen, not more than N (N - 2) to put the second one, not more than N(N - 2)(N - 4) for the third one etc. In total that results in \mathcal{O}(N!)O(N!) time complexity.
Space complexity : \mathcal{O}(N)O(N) to keep an information about diagonals and rows.*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        /* All below vectors are estabilished during the processes in below functions*/
        
        vector<vector<string>> Solutions; // solition vection
        vector<string> oneSol;// vector for one sol
        vector<pair<int, int>> path;    //vector for <i,j> pairs  ,pair  g2(1, 'a');  //initialized,  different data type   
        dfs(0, n, path, oneSol, Solutions); // dfs search to find solutions
        
        return Solutions;
    }
    
    
    void dfs(int i, int n, vector<pair<int, int>>& path, vector<string>& oneSol, vector<vector<string>>& Solutions){// all vectors passed by referrence, but when used ,as normap 
        if(i == n){
            Solutions.push_back(oneSol);
            return;
        }
        
        for(int j = 0; j < n; j++){
            bool add = true;
            pair<int, int> candiate = make_pair(i, j);// make_pair is a function in pair
            
            // horizontal tranverse pairs
            for(auto P: path){
                if(isAttackable (P, candiate)){
                    add = false;
                    break;
                }
            }
            // can't combine with above for loop since need to make sure candidate(pair values state the same)
            if(add){
                path.push_back(candiate);
                string row(n, '.');
                row[j] = 'Q';
                oneSol.push_back(row);
                dfs(i + 1, n, path, oneSol, Solutions);
                oneSol.pop_back();
                path.pop_back(); 
            }
        }
        
        //end of dfs function
    }
    
    
    // check for diagnal attack 
    bool isAttackable(pair<int, int> P1, pair<int, int> P2){ 
        if(P2.second == P1.second || abs(P2.second - P1.second) == abs(P2.first - P1.first)) return true;
        return false;
    }
};

