class Solution {
public:
    const int c=1e9+7;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,c));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                    dp[i][j]=matrix[i][j];
                    continue;
                }
                int up=c;
                int left=c;
                int right=c;
                up=dp[i-1][j];
                if(j!=0)
                {
                    left=dp[i-1][j-1];
                }
                if(j!=n-1)
                {
                    right=dp[i-1][j+1];
                }
                dp[i][j]=matrix[i][j]+min({up,left,right});

            }
        }
        int ans=c;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
