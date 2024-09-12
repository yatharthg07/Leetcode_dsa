
#define ll unsigned long long int
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
        for(ll i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }

        }
        return dp[n][m];

    }
};