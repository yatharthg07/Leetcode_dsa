class Solution {
public:
    // int solve(vector<vector<int>>& dp, vector<int>& cuts, int i, int j) {
    //     int ans = 1e9;
    //     if (i > j) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     for (int k = i; k <= j; k++) {

    //         int res = solve(dp, cuts, i, k - 1) + solve(dp, cuts, k + 1, j) +
    //                   cuts[j + 1] - cuts[i - 1];
    //         ans = min(res, ans);
    //     }
    //     return dp[i][j] = ans;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));
        for (int i = cuts.size() - 2; i>=1; i -- ) {
            for (int j = i; j < cuts.size() - 1; j++) {
                int ans = 1e9;

                for (int k = i; k <= j; k++) {

                    int res =
                        dp[i][k - 1] + dp[k + 1][j] + cuts[j + 1] - cuts[i - 1];
                    ans = min(res, ans);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][cuts.size()-2];
    }
};