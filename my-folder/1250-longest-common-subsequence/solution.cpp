// RECURSION WITH MEMOISATION
// class Solution {
// public:
//     int lcs(string& text1, string& text2, int n, int m, vector<vector<int>>& dp) {
//         if (n == 0 || m == 0) {
//             return 0;
//         }

//         if (dp[n][m] != -1) {
//             return dp[n][m];
//         }

//         if (text1[n - 1] == text2[m - 1]) {
//             dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1, dp);
//         } else {
//             dp[n][m] = max(lcs(text1, text2, n - 1, m, dp), lcs(text1, text2, n, m - 1, dp));
//         }

//         return dp[n][m];
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length();
//         int m = text2.length();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return lcs(text1, text2, n, m, dp);
//     }
// };





class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    cur[j]=1+prev[j-1];
                    
                    
                }
                else
                {
                    cur[j]=max(prev[j],cur[j-1]);
                    
                }
            }
            prev=cur;
            
        }
        return cur[m];
        
    }
};
