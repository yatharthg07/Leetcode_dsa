class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=INT_MAX;
                int left=INT_MAX;
                int right=INT_MAX;  
                if(j!=0)
                {
                    left=dp[i-1][j-1];
                }
                if(j!=n-1)
                {
                    right=dp[i-1][j+1];
                }
                up=dp[i-1][j];
                dp[i][j]=min({up,right,left})+matrix[i][j];                
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
        
    }
};