class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int cursum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(cursum<0)
            {
                cursum=0;
            }
            cursum+=nums[i];

            maxsum=max(maxsum,cursum);
        }
        return maxsum;
        
    }
};