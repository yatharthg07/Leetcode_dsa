vector<vector<int>> dp(21,vector<int>(1001));
class Solution {
public:

    int countsum(vector<int>& nums, int s1)
    {
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][s1];

        


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s1=(sum+target)/2;
        if((sum+target)%2!=0 || (sum+target)<0)
        {
            return 0;
        }
        else 
        {
            return countsum(nums,s1);
        }
        
    }
};
