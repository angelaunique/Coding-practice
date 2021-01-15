class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     
        // method1 recursion
        /* f(n) = min{f(n-c)+1}  recursively add
        边界f(0) = 0
        需要使用 memory
        f(6) = f(5)的解法+ 1（value of coin =1)
        f(5)= (1,4),(2,3) (1,1,2,1)... tree, use memory to save f(1),f(2)..
        
        */
        // method1: time complexity n^2
       vector<int> dp(amount+1, INT_MAX) ;  // since amount dp[i] index start with -1, thus total amout is amount+1,初始值均为INT_MAX 
        dp[0] = 0; //第一列amunt 为0 时所有币值对应都数量为0  dp[i] 为各个币值对应的所需要硬币数量 = 6（1）+3（2）+2（5） = 22 
        //虽然分析图看起来像matrix,那是因为分析时amont所有数值都列出了，但实际只有一个amount，因为 dp的值被不断更新中，滚动数组 
            for (auto & coin: coins){
                for( int  i = amount - coin; i >= 0; i--) //i: i 为剩余 amount
                    if(dp[i] != INT_MAX )//if #type != -1
                        for( int k = 1; k* coin + i <= amount;++k)//k为从一枚此类型的硬币,在不超过amount
                            dp[i + k * coin] = min(dp[i + k * coin], dp[i] + k);//上一轮为dp[i] + k 因为for loop结尾处已经k++了
                            // dp[i + k * coin] = amont  // 此轮的dp[i]= dp[i + k * coin]合法，那么 dp[i] + k 也是合法的
            }
            return dp[amount] == INT_MAX? -1: dp[amount];
    }
    
    //method 2 recursion with dp
     vector<int> dp(amount+1, amount+1) ;  // amount +1 个位置，后面一个 amount +1  为invalid数值，不合法时用来return
        dp[0] = 0; //
            for (auto & coin: coins){
                for( int  i = coin; i <= amount; ++i) //i为使用当前一枚硬币   
                            dp[i] = min(dp[i], dp[i - coin] + 1);//上一轮为dp[i] + k 因为for loop结尾处已经k++了
                           // i = i - coin + coin， dp[i - coin]假设存在，+1 为多使用一枚硬币 dp[i] 为不用i th coin, dp[i - coin] + 1为用ith coin
            } 
            return dp[amount] >= amount+1? -1: dp[amount];
    }
        // best method dfs search + gready + pruning  先使用大的硬币
    Solution3:

    

C++ / DFS

Time complexity: O(amount^n/(coin_0*coin_1*…*coin_n))

Space complexity: O(n)
/*
Solution3: top down

C++ / DFS

Time complexity: O(amount^n/(coin_0*coin_1*…*coin_n))

Space complexity: O(n)*/
 int coinChange(vector<int>& coins, int amount) {
        // Sort coins in desending order
        std::sort(coins.rbegin(), coins.rend());//降序排序
        int ans = INT_MAX;//无解
        coinChange(coins, 0, amount, 0, ans); //调用helper function
        return ans == INT_MAX ? -1 : ans;
    }
private:
    void coinChange(const vector<int>& coins, 
                    int s, int amount, int count, int& ans) {//s = 0, count = 0
       //s起始搜索位置
        const int coin = coins[s];  
        
       // last element
        if( s == coins.size() -1) {
            if( amount % coin == 0)
                ans = min( ans, count +  amount/coin);// will work even amoun = 0
        
        } else{     
        for (int k = amount / coin; k >= 0 && count + k < ans; k--)
            coinChange(coins, s + 1, amount - k * coin, count + k, ans);
            }
        }   

};
