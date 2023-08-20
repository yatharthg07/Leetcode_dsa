class Solution {
public:


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]==0;
                    continue;
                }
                if(i==0&&j==0)
                {
                    dp[i][j]=1;
                    continue;
                }

                int l=0;
                int r=0;
                if(i>0)
                {
                    l=dp[i-1][j];
                    
                }       
                if(j>0)
                {
                    r=dp[i][j-1];
                    
                }
                dp[i][j]=l+r;
            }
        }
        return dp[m-1][n-1];
    }
};
