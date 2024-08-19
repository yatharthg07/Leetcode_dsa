class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        
        dp[1][0] = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] == INT_MAX) continue; 
                
                dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                

                if (i + j <= n) {
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int j = 0; j <= n; ++j) {
            result = min(result, dp[n][j]);
        }
        
        return result;
    }
};