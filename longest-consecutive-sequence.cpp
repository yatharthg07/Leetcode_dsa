class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]=0;
        }
        int ans=0;
        for(auto it:nums)
        {

            int cnt=0;
            if(mp.find(it-1)==mp.end() && !mp[it])
            {
                int i=it;
                while(mp.find(i)!=mp.end())
                {   
                    mp[i]=1;
                    cnt++;
                    i++;
                }

            }
            ans=max(ans,cnt);
        }
        return ans;

        
    }
};