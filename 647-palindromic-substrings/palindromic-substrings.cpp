class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int count = 0;

        // Single character substrings are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            count++; // Each single character is a palindrome
        }

        // Check for two-character palindromes
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++; // Increment count for two-character palindromes
            }
        }

        // Check for palindromes of length 3 and more
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                // Check if s[i] and s[j] are the same and the inner substring is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++; // Increment count for palindromes
                }
            }
        }

        return count;
    }
};
