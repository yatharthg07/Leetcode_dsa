class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int n = s.length(), count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // dp[i][j] represents whether the substring from index i to j is a palindrome
        for (int i = n - 1; i >= 0; i--) // start from the end of the string
        {
            for (int j = i; j < n; j++) // check substrings from i to j
            {
                // either length of palindrome is < 3 or inner substring is a palindrome
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) 
                {
                    dp[i][j] = true; // mark as palindrome
                    count++;         // increase count
                }
            }
        }
        
        return count;
    }
};
