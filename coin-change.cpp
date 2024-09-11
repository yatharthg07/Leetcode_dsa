class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,INT_MAX-1));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(i>=1)
                {
                    dp[i][j]=dp[i-1][j];
                }
                if(j-arr[i]>=0)
                {
                    dp[i][j]=min(dp[i][j],dp[i][j-arr[i]]+1);
                }
                
            }
        }
        return dp[n-1][amount]==INT_MAX-1?-1:dp[n-1][amount];

        
    }
};