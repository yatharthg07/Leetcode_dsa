class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;

        // Initialize the dp array
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        // Base case: 1 'A' on screen, with a copy size of 0 (initially no copy is done)
        dp[1][0] = 0;

        for (int currLen = 1; currLen < n; ++currLen) {
            for (int pasteLen = 0; pasteLen <= currLen; ++pasteLen) {
                if (dp[currLen][pasteLen] == INT_MAX) continue;

                // Option 1: Paste the last copied text (if something was copied)
                if (pasteLen > 0 && currLen + pasteLen <= n) {
                    dp[currLen + pasteLen][pasteLen] = min(dp[currLen + pasteLen][pasteLen], dp[currLen][pasteLen] + 1);
                }

                // Option 2: Copy all current text and paste (double the current length)
                if (currLen * 2 <= n) {
                    dp[currLen * 2][currLen] = min(dp[currLen * 2][currLen], dp[currLen][pasteLen] + 2);
                }
            }
        }

        // We want the minimum steps to reach exactly n 'A's
        int minSteps = INT_MAX;
        for (int pasteLen = 1; pasteLen <= n; ++pasteLen) {
            minSteps = min(minSteps, dp[n][pasteLen]);
        }

        return minSteps;
    }
};

