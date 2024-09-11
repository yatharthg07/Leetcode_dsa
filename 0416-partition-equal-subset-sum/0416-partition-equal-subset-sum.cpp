class Solution {
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n=arr.size();        
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        for(int j=0;j<=target;j++)
        {
            dp[0][target]=0;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(j-arr[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]];
                }
                dp[i][j]=dp[i][j]|dp[i-1][j];
            }
        }
        return dp[n][target]==1;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)
        {
            return 0;
        }
            return isSubsetSum(nums,sum/2);
        
    }
};