class Solution {
public:
    int help(vector<int> & nums,int k)
    {
        int l=0;int r=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int res=0;
        while(r<n)
        {
            if(mp.find(nums[r])==mp.end())
                mp[nums[r]]=1;
            else
                mp[nums[r]]++;    
            while(mp.size()>k)
            {
                if(mp[nums[l]]==1)
                    mp.erase(nums[l++]);
                else
                    mp[nums[l++]]--;    
            }
            res+=r-l+1;
            r++;


        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
        
    }
};
