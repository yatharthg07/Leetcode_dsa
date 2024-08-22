class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        int presum;
        presum=0;
        unordered_map<int,int> mp;
        mp[0]++;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            presum+=nums[i];
            cnt+=mp[presum-k];
            mp[presum]++;
            

        }
        // for(int i=0;i<n;i++)
        // {
        //     if(mp.find(presum[i]-k)!=mp.end())
        //     {
        //         auto st=mp[presum[i]-k];
        //         for(auto it:st)
        //         {
        //             if(it<i)
        //             {
        //                 cnt++;
        //             }
        //         }
        //     }
        // }
        return cnt;



        
    }
};