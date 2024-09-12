class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;  // Edge case for empty prices array
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base cases
        dp[0][0] = 0;               // On day 0, not holding stock = 0 profit
        dp[0][1] = -prices[0];       // On day 0, holding stock = -prices[0] (bought it)
        
        for (int i = 1; i < n; i++) {
            // State transitions for dp[i][0] and dp[i][1]
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);  // Either keep not holding or sell today
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);  // Either keep holding or buy today
        }
        
        // Final result: max profit at the end without holding any stock
        return dp[n-1][0];
    }
};
