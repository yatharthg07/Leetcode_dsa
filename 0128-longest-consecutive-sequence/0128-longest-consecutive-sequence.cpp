class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto it:nums)
        {
            mp.insert(it);
        }
        int ans=0;
        for(auto it:nums)
        {

            int cnt=0;
            if(mp.find(it-1)==mp.end())
            {
                int i=it;
                while(mp.find(i)!=mp.end())
                {   
                    cnt++;
                    i++;
                }

            }
            ans=max(ans,cnt);
        }
        return ans;

        
    }
};