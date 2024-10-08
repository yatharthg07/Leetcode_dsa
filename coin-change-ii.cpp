class Solution {
public:
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int j=1;j<=amount;j++)
        {
            dp[0][j]=0;
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j-arr[i-1]>=0)
                {
                    dp[i][j]+=dp[i][j-arr[i-1]];
                }
                
            }
        }
        return dp[n][amount];
        
    }
};