#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        vector<ll> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        ll sum=pre[n-1];
        int target=sum%p;
        if(target==0)
        {
            return 0;
        }
        unordered_map<int,int> mp;
        int ans=n;
        for(int i=0;i<n;i++)
        {
            int rem=pre[i]%p;
            if(rem==target) {
                ans=min(ans,i+1);
            }
            int tar=(rem-target+p)%p;
            if(mp.find(tar)!=mp.end())
            {
                ans=min(ans,i-mp[tar]);
            }
            mp[rem]=i;
        }
        return ans==n?-1:ans;
    }
};