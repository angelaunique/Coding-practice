/*18. Coin Change 2

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
*/
// reference to this vedio for recursion dgram
//https://www.youtube.com/watch?v=Nvrhx4lbfLI 
/// reference to this vedio for recursion dgram
//https://www.youtube.com/watch?v=Nvrhx4lbfLI 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
     
        return change( amount, coins, 0) ;
        }
    
    int change(int amount, vector<int>& coins, int i ){
        if (amount < 0 )  return 0;
        if(amount ==0 ) return 1;
        
        
       // for( int i = begin; i < coins.size(); i ++) // i is increasing in helper ,don't need a for loop here!
          //  return  helper( amount - coins[i],  coins, begin+1 )+1 ;        
        if (i == coins.size() && amount > 0) return 0; // means coins over and n>0 so no solution, boundary for i 
        return change(amount - coins[i], coins, i) + change(amount, coins, i + 1); // include + exclude
        // 注意dp 由两部分组成！！！包括+不包括
    }     
};
// top down

class Solution {
    public int change(int amount, int[] coins) {
        Integer[][] dp = new Integer[amount + 1][coins.length + 1];
        for (int i = 1; i < dp.length; i++) {
            dp[i][0] = 0;
        }   
        for (int i = 0; i < dp[0].length; i++) {
            dp[0][i] = 1;
        }
        return change(amount, coins.length, coins, dp);
    }

    private int change(int amount, int coinsLengthToInclude, int[] coins, Integer[][] dp) {
        if (amount < 0) {
            return 0;
        }
        if (dp[amount][coinsLengthToInclude] == null) {
            dp[amount][coinsLengthToInclude] = change(amount, coinsLengthToInclude - 1, coins, dp) +change(amount - coins[coinsLengthToInclude - 1], coinsLengthToInclude, coins, dp);
        }
        return dp[amount][coinsLengthToInclude];
    }
}

//看视频dp 推倒过程！！ https://www.youtube.com/watch?v=Nvrhx4lbfLI 
//Bottom Up 2D-DP

  public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length+1][amount+1];
        dp[0][0] = 1;
        
        for (int i = 1; i <= coins.length; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[coins.length][amount];
    }
    
// 1Dimension 优化
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int n=coins.size();
		vector<int> dp(amount+1,0);
		dp[0]=1;
		for(int c:coins)
			for(int j= c ;j<=amount;j++){
					 dp[j]+=dp[j-c];
				}          
		return dp[amount];  
	}
};