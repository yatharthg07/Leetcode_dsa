class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(k*2+1, 0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<k*2;j++)
            {
                if(j%2==0)
                    dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                else
                    dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }

        }
        
        return dp[0][0];
    }
};