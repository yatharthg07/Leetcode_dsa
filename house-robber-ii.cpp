class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int ans=INT_MIN;
        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        ans=dp[n-2];
        dp=vector<int> (n);
        dp[1]=nums[1];
        dp[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        ans=max(ans,dp[n-1]);
        return ans;


        
        
    }
};