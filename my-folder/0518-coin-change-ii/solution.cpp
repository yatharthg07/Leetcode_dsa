class Solution 
{
    public:
    int change(int amount, vector<int>& coins) 
    {
        int size=coins.size();
        // vector<vector<int>> dp(size+1,vector<int>(amount+1,0));
        vector<int> dp(amount+1,0);
        dp[0]=1;
        // for(int i=0;i<=size;i++)
        // {
        //     for(int j=0;j<=amount;j++)
        //     {
        //         if(i==0)
        //         {
        //             dp[i][j]=0;
        //         }
        //         if(j==0)
        //         {
        //             dp[i][j] =1;
                               
                               
        //         }                   

        //     }
        // }    
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[j]+=dp[j-coins[i-1]];
                }

            
            }


        }
        return dp[amount];

        
        
    }
};
