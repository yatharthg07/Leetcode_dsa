class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

        // Initialize the base cases: when there are no piles left, the result is 0.
        for (int M = 0; M <= n; ++M) {
            dp[0][n][M] = 0;
            dp[1][n][M] = 0;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                int stones = 0;
                dp[1][i][M] = 0;
                dp[0][i][M] = INT_MAX;

                for (int x = 1; x <= min(2 * M, n - i); ++x) {
                    stones += piles[i + x - 1];

                    // Alice's turn: maximize stones
                    dp[1][i][M] = max(dp[1][i][M], stones + dp[0][i + x][max(M, x)]);

                    // Bob's turn: minimize the result (which minimizes Alice's stones)
                    dp[0][i][M] = min(dp[0][i][M], dp[1][i + x][max(M, x)]);
                }
            }
        }

        return dp[1][0][1]; // Alice starts the game
    }
};
