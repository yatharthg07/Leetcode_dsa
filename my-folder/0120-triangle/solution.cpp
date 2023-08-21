class Solution {
public:
    const int c=1e9+7;
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,c));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=triangle[i][j];
                    continue;
                }
                int up=c;
                int left=c;
                if(j<triangle[i-1].size())
                {
                    up=dp[i-1][j]+triangle[i][j];
                }
                if(j!=0)
                {
                    left=dp[i-1][j-1]+triangle[i][j];
                }
                dp[i][j]=min(up,left);
            }
        }
        int res=1e9;
        for(int i=0;i<triangle[n-1].size();i++)
        {
            res=min(res,dp[n-1][i]);
        }
        return res;
        
    }
};
