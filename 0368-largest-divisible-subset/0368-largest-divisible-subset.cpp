class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> par(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        par[i]=j;
                    }
                }
            }
        }
        auto it=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int> ans;
        ans.push_back(nums[it]);
        while(par[it]!=it)
        {
            it=par[it];
            ans.push_back(nums[it]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};