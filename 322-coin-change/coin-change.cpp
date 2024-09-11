class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<int> curr(amount+1,INT_MAX-1);
        // vector<vector<int>> dp(n,vector<int> (amount+1,INT_MAX-1));
        // for(int i=0;i<n;i++)
        // {
        //     dp[i][0]=0;
        // }
        curr[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(i>=1)
                {
                    curr[j]=curr[j];
                }
                if(j-arr[i]>=0)
                {
                    curr[j]=min(curr[j],curr[j-arr[i]]+1);
                }
                
            }
        }
        return curr[amount]==INT_MAX-1?-1:curr[amount];

        
    }
};