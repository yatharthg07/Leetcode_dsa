class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INT_MIN));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= i; t++) {
                dp[i][t] = max(dp[i-1][t-1] + satisfaction[i-1] * t, dp[i-1][t]);
            }
        }

        long long maxSatisfaction = 0;
        for (int t = 1; t <= n; t++) {
            maxSatisfaction = max(maxSatisfaction, dp[n][t]);
        }

        return maxSatisfaction;
    }
};
