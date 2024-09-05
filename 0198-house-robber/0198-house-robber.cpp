class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int notpick=f(i-1,nums,dp);
        int pick= nums[i]+f(i-2,nums,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp0(n);
        // vector<int> dp1(n);
        // dp1[0]=nums[0];
        // dp0[0]=0;

        // for(int i=1;i<n;i++)
        // {
        //     dp1[i]=max(dp1[i],dp0[i-1]);
        //     dp0[i]=max({dp0[i],dp1[i-1],dp0[i-1]});
        // }
        // return max(dp1[n],dp0[n]);
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);


        
    }
};