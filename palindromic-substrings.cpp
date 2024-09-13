class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n+1,vector<bool> (n,0));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                if(s[j]==s[j+i-1])
                {
                    dp[i][j]=dp[i-2][j+1]||dp[i][j];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                ans+=dp[i][j];
            }

        }
        return ans;

    }
};