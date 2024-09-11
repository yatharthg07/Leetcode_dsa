class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int up=INT_MAX;
                int left=INT_MAX;
                if(j!=0)
                {
                    left=dp[i-1][j-1];
                }
                if(j<i)
                {
                    up=dp[i-1][j];
                }
                dp[i][j]=min(up,left)+triangle[i][j];
                
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());

        
    }
};