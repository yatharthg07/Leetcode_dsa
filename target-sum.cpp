class Solution {
public:

    int MOD=1e9+7;
  	int perfectSum(vector<int>& arr, int n, int target)
	{
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
                    dp[i][j]=dp[i-1][j-arr[i-1]]%MOD;
                }
                dp[i][j]+=dp[i-1][j]%MOD;
            }
        }
        return dp[n][target]%MOD;
	}
	  
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((sum+d)%2!=0||(sum+d)/2<0)
        {
            return 0;
        }
        return perfectSum(arr,n,(sum+d)/2);


        
    }
};