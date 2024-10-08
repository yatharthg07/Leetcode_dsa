class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(auto num:nums)
            {
                if(num&(1<<i))
                {
                    cnt++;
                }
            }
            if(cnt%3==1)
            {
                ans=ans|(1<<i);
            }
        }
        return ans;
        
    }
};