class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int> (n,0));
        // vector<int> prev(n);
        vector<int> curr(n);
        // prev[0]=grid[0][0];
        curr[0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0)
                {
                    up=curr[j];
                }
                if(j>0)
                {
                    left=curr[j-1];
                }
                curr[j]=min(up,left)+grid[i][j];
            }
        }
        return curr[n-1];
        
        
    }
};