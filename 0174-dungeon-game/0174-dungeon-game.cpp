class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {    
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,1e9));
        dp[n-1][m-1]=dungeon[n-1][m-1]<0?-dungeon[n-1][m-1]+1:1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1&&j==m-1)
                {
                    continue;
                }
                int top=INT_MAX;
                int left=INT_MAX;
                if(j<m-1)
                {
                    left=dungeon[i][j]-dp[i][j+1]<0?-(dungeon[i][j]-dp[i][j+1]):1;
                }
                if(i<n-1)
                {
                    top=dungeon[i][j]-dp[i+1][j]<0?-(dungeon[i][j]-dp[i+1][j]):1;
                }
                dp[i][j]=min(top,left);
            
            }
        }
        return dp[0][0];

        
    }
};