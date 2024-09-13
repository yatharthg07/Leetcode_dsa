class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;  // Special case for empty string or starting with '0'

        // dp[i] means the number of ways to decode the substring s[0...i-1]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: There's 1 way to decode an empty string.
        
        // Initialize dp[1]
        dp[1] = (s[0] != '0') ? 1 : 0;  // The first character can be decoded if it's not '0'
        
        // Fill the dp array from 2 to n
        for (int i = 2; i <= n; i++) {
            // Single character decode (s[i-1])
            if (s[i-1] != '0') {
                dp[i] = dp[i-1];
            }
            
            // Two characters decode (s[i-2] and s[i-1])
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];  // The result is stored in dp[n], representing the number of ways to decode the entire string
    }
};
