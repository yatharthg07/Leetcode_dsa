class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 + n2 != s3.length()) return false;
        
        // DP table with default false values
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n1; ++i)
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= n2; ++j)
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        
        return dp[n1][n2];
    }
};
