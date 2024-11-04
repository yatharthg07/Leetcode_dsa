int MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD;
            dp[i][0] = (dp[i][0] + dp[i - 2][0]) % MOD;

            dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % MOD;

            dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % MOD;
        }
        return dp[n][0];
    }
};
