class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxday = days[n - 1];
        
        // Use a set to keep track of travel days for quick lookup
        unordered_set<int> travel_days(days.begin(), days.end());
        
        // DP array to store the minimum cost up to each day
        vector<int> dp(maxday + 1, 0);
        
        for (int i = 1; i <= maxday; i++) {
            // If today is not a travel day, cost stays the same as the previous day
            if (travel_days.find(i) == travel_days.end()) {
                dp[i] = dp[i - 1];
                continue;
            }
            
            // Option 1: Buy a 1-day pass
            dp[i] = dp[i - 1] + costs[0];
            
            // Option 2: Buy a 7-day pass, looping from `i-7` to `i-1`
            for (int j = i - 7; j <= i - 1; j++) {
                if (j >= 0) { // Ensure we're within bounds
                    dp[i] = min(dp[i], dp[j] + costs[1]);
                }
            }
            
            // Option 3: Buy a 30-day pass, looping from `i-30` to `i-1`
            for (int j = i - 30; j <= i - 1; j++) {
                if (j >= 0) { // Ensure we're within bounds
                    dp[i] = min(dp[i], dp[j] + costs[2]);
                }
            }
        }

        // The answer is the minimum cost to cover all travel days
        return dp[maxday];
    }
};
