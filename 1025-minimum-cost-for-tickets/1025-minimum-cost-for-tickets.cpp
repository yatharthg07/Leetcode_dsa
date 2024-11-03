class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxday = days[n - 1];
        unordered_set<int> travel_days(days.begin(), days.end());
        vector<int> dp(maxday + 1, 0);

        for (int i = 1; i <= maxday; i++) {
            if (travel_days.find(i) == travel_days.end()) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = dp[i - 1] + costs[0]; 
            dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]); 
        }

        return dp[maxday];
    }
};
