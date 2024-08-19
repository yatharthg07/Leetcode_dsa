
class Solution {
public:
    int minSteps(int n) {
        // Define dp table with large initial values
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        
        // Base case: starting with 1 'A' and nothing copied
        dp[1][0] = 0;
        
        // Fill dp table
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] == INT_MAX) continue; // Skip unreachable states
                
                // Option 1: Copy All, set last copied length to i
                dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                
                // Option 2: Paste, add last copied length j to current length i
                if (i + j <= n) {
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                }
            }
        }
        
        // Find the minimum steps to get exactly n 'A's
        int result = INT_MAX;
        for (int j = 0; j <= n; ++j) {
            result = min(result, dp[n][j]);
        }
        
        return result;
    }
};
