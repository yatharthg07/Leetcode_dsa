class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size();

        vector<vector<int>> dp(size+1,vector<int>(amount+1,INT_MAX-1));
        for(int i=0;i<=size;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                {
                    dp[i][j] =0;              
                 }

            }

        }
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=amount;j++)
            {

                if(coins[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {

                        dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                    
                }

                
            }
        }
        if(dp[size][amount]==INT_MAX-1)
        {
            return -1;
        }
        else
        {
        return dp[size][amount];}
        
    }
};



