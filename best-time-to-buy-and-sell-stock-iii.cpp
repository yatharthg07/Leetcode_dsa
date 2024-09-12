class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(4, 0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<4;j++)
            {   
                dp[i][0]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                dp[i][1]=max(prices[i]+dp[i+1][2],dp[i+1][1]);
                dp[i][2]=max(-prices[i]+dp[i+1][3],dp[i+1][2]);
                dp[i][3]=max(prices[i],dp[i+1][3]);
            }    

        }
        
        return dp[0][0];
        
    }
};