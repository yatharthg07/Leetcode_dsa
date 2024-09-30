#define ll long long

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll sum=accumulate(cost.begin(),cost.end(),0ll);
        ll med=(sum+1ll)/2ll;
        vector<pair<ll,ll>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        ll pre=0;
        ll ele=0;
        for(auto [n,c]:v)
        {
            pre+=c;
            if(pre>=med)
            {
                ele=n;
                break;
            }
        }
        ll ans=0;
        for(auto [n,c]:v)
        {
            ans+=(abs(ele-n)*c);
        }
        return ans;
        
    }
};