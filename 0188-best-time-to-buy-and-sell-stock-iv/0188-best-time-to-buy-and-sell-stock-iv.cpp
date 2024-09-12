class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2*k, 0));

        for(int i=n-1;i>=0;i--)
        { 
                for(int j=0;j<2*k-2;j+=2)
                {    
                    dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                    dp[i][j+1]=max(prices[i]+dp[i+1][j+2],dp[i+1][j+1]);
                }
                dp[i][2*k-2]=max(-prices[i]+dp[i+1][2*k-1],dp[i+1][2*k-2]);
                dp[i][2*k-1]=max(prices[i],dp[i+1][2*k-1]); 

        }
        
        return dp[0][0];
    }
};